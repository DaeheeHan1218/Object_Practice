#include <iostream>
#include <fstream>
#include <sstream>
#include "Stress_ball.h"
#include "Collection.h"

using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

istream& operator>>(istream& is, CollectionSB& c){
	std::string clr;
	std::string sz;
	Stress_ball_colors color;
	Stress_ball_sizes size;
	while(is >> clr >> sz){
		if(clr == "red"){
			color = Stress_ball_colors::red;
		}else if(clr == "blue"){
			color = Stress_ball_colors::blue;
		}else if(clr == "yellow"){
			color = Stress_ball_colors::yellow;
		}else if(clr == "green"){
			color = Stress_ball_colors::green;
		}
		if(sz == "small"){
			size = Stress_ball_sizes::small;
		}else if(sz == "medium"){
			size = Stress_ball_sizes::medium;
		}else if(sz == "large"){
			size = Stress_ball_sizes::large;
		}
		c.insert_item(Stress_ball(color, size));
	}
	return is;
}

void test_stress_balls(){
    //Test 1
	cout << "Stress_ball test 1" << endl;
    CollectionSB collection_file;
    cout << "collection_file size: " << collection_file.total_items() << endl;
    ifstream ifs("stress_ball1.data");
    ifs >> collection_file;
    CollectionSB cpyCol1(collection_file);
    CollectionSB cpyCol2(collection_file);
    CollectionSB cpyCol3(collection_file);
        
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
    
	//Test 2
	cout << "Stress_ball test 2" << endl;
	collection_file.make_empty();
	ifstream ifs2("stress_ball2.data");
	ifs2 >> collection_file;
	cpyCol1 = collection_file;
	cpyCol2 = collection_file;
	cpyCol3 = collection_file;
        
    cout << "collection_file size: " << collection_file.total_items() << endl;
	cout << "how many red balls?: " << collection_file.total_items(Stress_ball_colors::red) << endl;
	cout << "how many medium balls?: " << collection_file.total_items(Stress_ball_sizes::medium) << endl;
       
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

