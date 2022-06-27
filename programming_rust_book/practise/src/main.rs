#[derive(Debug)]
struct Person {
      name: Option<String>,
      birth: i32
  }

fn main(){

let x = Person {
    name: Some(String::from("Andrew")), 
    birth: 20
};

println!("{:?}",x);

}
