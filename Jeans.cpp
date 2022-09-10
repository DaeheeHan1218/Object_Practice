#include "Jeans.h"
Jeans::Jeans(){
    int i = rand()%4;
    color = static_cast<Jeans_colors>(i);
    i = rand()%4;
	size = static_cast<Jeans_sizes>(i);
}

Jeans::Jeans(Jeans_colors c, Jeans_sizes s):color(c), size(s){}

Jeans_colors Jeans::get_color() const{
	return color;
}

Jeans_sizes Jeans::get_size() const{
	return size;
}

bool Jeans::operator==(const Jeans& sb){
	if(this->color == sb.color && this->size == sb.size){
		return true;
	}
	return false;
}

ostream& operator<<(ostream &o, const Jeans& sb){
	o << "(";
	Jeans tmp = sb;
	if(tmp.get_color() == Jeans_colors::white){
	    o << "white";
	}
	else if(tmp.get_color() == Jeans_colors::black){
	    o << "black";
	}
	else if(tmp.get_color() == Jeans_colors::blue){
	    o << "blue";
	}
	else if(tmp.get_color() == Jeans_colors::grey){
	    o << "grey";
	}
	
	if(tmp.get_size() == Jeans_sizes::small){
	    o << ", small)";
	}
	else if(tmp.get_size() == Jeans_sizes::medium){
	    o << ", medium)";
	}
	else if(tmp.get_size() == Jeans_sizes::large){
	    o << ", large)";
	}
	else if(tmp.get_size() == Jeans_sizes::xlarge){
	    o << ", xlarge)";
	}
	return o;
}