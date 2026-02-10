use std::env;
use anyhow::Context;
use lettre::{AsyncSmtpTransport, AsyncTransport, Message, Tokio1Executor, transport::smtp::authentication::Credentials};




pub async fn em_service(to : &str,code :i32)
    -> anyhow::Result<()>
{
    let from = env::var("EMAIL").context("Missing environment variable EMAIL")?;
    let pd = env::var("EMAIL_CODE").context("Missing environment variable EMAIL_CODE")?;
    let smtp_path = "smtp.163.com";

    let msg = Message::builder()
        .from(from.clone().parse()?)
        .to(to.parse()?)
        .subject("[LosChess]验证码是:")
        .body(
            format!(r"
    您好，您的验证码是:{},有效期是三分钟，请尽快登录!            
            ",code)
        )
        .context("创建邮件失败")?;

    let credentials = Credentials::new(from, pd);

    let bus:AsyncSmtpTransport<Tokio1Executor> = 
        AsyncSmtpTransport::<Tokio1Executor>::relay(smtp_path)?
            .credentials(credentials)
            .build();
    bus.send(msg).await.context("邮件发送失败")?;

    Ok(())
}