fn main(){
	
	enum Continent {
		Europe,
		Asia,
		Africa,
		America,
		Oceania,
	}
	let contin = Continent::Asia;
	
	match contin {
		Continent::Europe => print!("E"), 
		Continent::Asia => print!("As"),
		Continent::Africa => print!("Af"),
		Continent::America => print!("Am"),
		Continent::Oceania => print!("O"),
	}
	//2nd example within one program
	enum Result {
	Success(f64),
	Failure(u16,char),
	Uncertainty,
}
// let outcome = Result::Success(23.67);
let outcome = Result::Failure(1200,'X');

match outcome {
	Result::Success(value) => 
	print!("Result:{}",value),
	Result::Failure(error_code,module) =>
	print!("Error n.{} in module{}",
	error_code,module),
	
	Result::Uncertainty => {},
	
}
//Result Error n.1200 in moduleX
}
