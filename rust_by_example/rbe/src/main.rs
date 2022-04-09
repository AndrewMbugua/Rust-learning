fn reverse(pair: (i32, bool)) -> (bool,i32){


let (integer,boolean) = pair;

(boolean,integer)
}


fn main(){

let air = (1,true);

println!("{:?}",reverse(air));

}
