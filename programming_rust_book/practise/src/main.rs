struct Person{
    name: String,
    birth: i32
}


fn main(){

let mut compos = Vec::new();
compos.push(Person { name: "Andrew".to_string(), birth: 2000 });

for compos_ptr in &compos{

println!("{},{}",compos_ptr.name, compos_ptr.birth);


}
}
