
#pragma once
#include <QtGlobal>
#include <QDateTime>
#include <QThread>
#include <QString>
#include <QMessageLogContext>
#include <cinttypes>
#include <cstdint>  
#include <cstdio>


namespace Com {
	
	/// <summary>
	/// 根据 状态情况 返回对应的 字符串
	/// </summary>
	/// <param name="t"></param>
	/// <returns></returns>
	inline const char* levelStr(QtMsgType t)
	{
		switch (t)
		{
		case QtMsgType::QtInfoMsg: {
			return "INFO";
		}
		case QtMsgType::QtWarningMsg: {
			return "WARNING";
		}
		case QtMsgType::QtCriticalMsg: {
			return "WRONG";
		}
		case QtMsgType::QtDebugMsg: {
			return "DEBUG";
		}
		}
	};


	/// <summary>
	/// 重新 写 handle 进行消息注册
	/// </summary>
	/// <param name="type"></param>
	/// <param name="ctx"></param>
	/// <param name="msg"></param>
	inline void messageHandle(QtMsgType type, const QMessageLogContext& ctx, const QString& msg)
	{
		static std::mutex mtx;

		const QString time_ = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");
		const char* file = (ctx.file && ctx.file[0]) ? ctx.file : "?";
		const char* func = (ctx.function && ctx.function[0]) ? ctx.function : "?";
		const int line = ctx.line;

		const uintptr_t tid = reinterpret_cast<uintptr_t>(QThread::currentThreadId());
		const QByteArray utf8 = msg.toUtf8();

		std::lock_guard<std::mutex> lock(mtx);
		std::fprintf(stderr,
			"% s[% s][t:0x % " PRIxPTR "] % s: % d % s - % s\n",
			time_.toUtf8().constData(),
			levelStr(type),
			tid,
			file,
			line,
			func,
			utf8.constData());
		std::fflush(stderr);
		if (type == QtFatalMsg) {
			std::abort();
		}
	}

	inline void init()
	{
		static bool inited = false;
		if (inited) return;
		inited = true;
		qInstallMessageHandler(messageHandle);
	}


// 这个 Q_FUNC_INFO 就是把当前函数的信息 以 const char* 的方式进行返回
#define LOGD() QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug().noquote()
#define LOGI() QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).info().noquote()
#define LOGW() QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).warning().noquote()
#define LOGE() QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).critical().noquote()

};
