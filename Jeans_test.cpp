#include <iostream>
#include <fstream>
#include <sstream>
#include "Jeans.h"
#include "Collection.h"

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c){
	std::string clr;
	std::string sz;
	Jeans_colors color;
	Jeans_sizes size;
	while(is >> clr >> sz){
		if(clr == "white"){
			color = Jeans_colors::white;
		}else if(clr == "black"){
			color = Jeans_colors::black;
		}else if(clr == "blue"){
			color = Jeans_colors::blue;
		}else if(clr == "grey"){
			color = Jeans_colors::grey;
		}
		if(sz == "small"){
			size = Jeans_sizes::small;
		}else if(sz == "medium"){
			size = Jeans_sizes::medium;
		}else if(sz == "large"){
			size = Jeans_sizes::large;
		}else if(sz == "xlarge"){
			size = Jeans_sizes::xlarge;
		}
		c.insert_item(Jeans(color, size));
	}
	return is;
}

void test_jeans(){
	Jeans j1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
    Jeans j2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
    Jeans j3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
    Jeans j4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
    CollectionJN collection_file(1);
	//Jean Test 1
	std::cout << "Jeans Test 1" << std::endl;
    ifstream ifs("jeans1.data");
    ifs >> collection_file;
    collection_file.insert_item(j4);
    collection_file.insert_item(j3);
    collection_file.insert_item(j2);
    collection_file.insert_item(j1);
	
	CollectionJN cpyCol1(collection_file);
    CollectionJN cpyCol2(collection_file);
    CollectionJN cpyCol3(collection_file);
        
    cout << "is collection_file empty?: " << collection_file.is_empty() << endl;
    cout << "is cpyCol1 empty?: " << cpyCol1.is_empty() << endl;
    cout << "collection_file size: " << collection_file.total_items() << endl;
       
    sort_by_size(cpyCol1, Sort_choice::bubble_sort);
    sort_by_size(cpyCol2, Sort_choice::insertion_sort);
    sort_by_size(cpyCol3, Sort_choice::selection_sort);
        
    cout << "print collection_file: " << endl << collection_file << endl;
    cout << "print cpyCol1(bubble sorted): " << endl << cpyCol1 << endl;
    cout << "print cpyCol2(insertion sorted): " << endl << cpyCol2 << endl;
    cout << "print cpyCol3(selection sorted): " << endl << cpyCol3 << endl;
	//Jean Test 2
	collection_file.make_empty();
	cpyCol1.make_empty();
	cpyCol2.make_empty();
	cpyCol3.make_empty();
	std::cout << "Jeans Test 2" << std::endl;
    ifstream ifs2("jeans2.data");
	ifs2 >> collection_file;
	
	cpyCol1 = collection_file;
    cpyCol2 = collection_file;
    cpyCol3 = collection_file;
        
	cout << "collection_file size: " << collection_file.total_items() << endl;
    cout << "how many blue jeans?: " << collection_file.total_items(Jeans_colors::blue) << endl;
    cout << "how many xlarge jeans?: " << collection_file.total_items(Jeans_sizes::xlarge) << endl;
       
    sort_by_size(cpyCol1, Sort_choice::bubble_sort);
    sort_by_size(cpyCol2, Sort_choice::insertion_sort);
    sort_by_size(cpyCol3, Sort_choice::selection_sort);
        
    cout << "print collection_file: " << endl << collection_file << endl;
    cout << "print cpyCol1(bubble sorted): " << endl << cpyCol1 << endl;
    cout << "print cpyCol2(insertion sorted): " << endl << cpyCol2 << endl;
    cout << "print cpyCol3(selection sorted): " << endl << cpyCol3 << endl;
	collection_file.~Collection();
    cpyCol1.~Collection();
    cpyCol2.~Collection();
    cpyCol3.~Collection();
}
