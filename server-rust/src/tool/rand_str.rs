
use rand;

fn rand_str() -> String{
    let code = rand::random_range(1000..9999);
    code.to_string()
}


