use std::collections::HashMap;

type Table = HashMap<String, Vec<String>>;

fn show(table: &Table){

for (artist, works) in table{
    println!("works by{}:",artist);

    for work in works {
        println!("  {}",work);
    }
}
}

fn main(){
    

    let mut table = Table::new();
    table.insert("Gesualdo".to_string(), vec!["Many madrigals".to_string(),"Tenebrae Res".to_string()]);

    table.insert("Caravaggio".to_string(), vec!["The Musicians".to_string(), "The Calling of St. Matthew".to_string()]);

    table.insert("Cellini".to_string(), vec!["Perseus with medusa's head".to_string(), "a salt cellar".to_string() ]);

    show(&table);       

      

}
