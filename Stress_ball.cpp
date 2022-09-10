#include "Stress_ball.h"
Stress_ball::Stress_ball(){
    int i = rand()%4;
    color = static_cast<Stress_ball_colors>(i);
    i = rand()%3;
	size = static_cast<Stress_ball_sizes>(i);
}

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s):color(c), size(s){}

Stress_ball_colors Stress_ball::get_color() const{
	return color;
}

Stress_ball_sizes Stress_ball::get_size() const{
	return size;
}

bool Stress_ball::operator==(const Stress_ball& sb){
	if(this->color == sb.color && this->size == sb.size){
		return true;
	}
	return false;
}

ostream& operator<<(ostream &o, const Stress_ball& sb){
	o << "(";
	Stress_ball tmp = sb;
	if(tmp.get_color() == Stress_ball_colors::red){
	    o << "red";
	}
	else if(tmp.get_color() == Stress_ball_colors::blue){
	    o << "blue";
	}
	else if(tmp.get_color() == Stress_ball_colors::yellow){
	    o << "yellow";
	}
	else if(tmp.get_color() == Stress_ball_colors::green){
	    o << "green";
	}
	
	if(tmp.get_size() == Stress_ball_sizes::small){
	    o << ", small)";
	}
	else if(tmp.get_size() == Stress_ball_sizes::medium){
	    o << ", medium)";
	}
	else if(tmp.get_size() == Stress_ball_sizes::large){
	    o << ", large)";
	}
	return o;
}