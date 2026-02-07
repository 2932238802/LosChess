

/*
26_2_4
- 这里是作为脚本
*/
fn main()
{
    prost_build::compile_protos(
        &[
            "../protofile/auth_request.proto",
            "../protofile/auth_response.proto"
        ]
        , 
        &["../protofile"]
    )
    .unwrap_or_else(|e| panic!("Failed to compile protos: {:?}", e));
}