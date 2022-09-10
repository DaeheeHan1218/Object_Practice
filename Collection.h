#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Stress_ball.h"
#include "Jeans.h"

//Color=F1; Size=F2; SB=Obj
enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

class Empty_Collection{};

template <typename Obj, typename F1, typename F2>
class Collection{
    Obj* array;
    int size;
    int capacity;
    void resize(){
		int newCap;
		if(capacity == 0){
			newCap = 1;
		}
		else{
			newCap = capacity * 2;
		}
		Obj* newArr = new Obj[newCap];
		for(int i = 0; i < size; i++){
			newArr[i] = array[i];
		}
		array = nullptr;
		delete array;
		array = newArr;
		capacity = newCap;
	}
public:
    Collection():array(nullptr), size(0), capacity(0){}
    Collection(int cap): array(new Obj[cap]), size(0), capacity(cap){}
    Collection(const Collection& c): array(new Obj[c.capacity]), size(c.size), capacity(c.capacity){
		for(int i = 0; i < size; i++){
			array[i] = c.array[i];
		}
	}
    Collection& operator=(const Collection& c){
		if(this != &c){
			size = c.size;
			capacity = c.capacity;
			Obj* newArr = new Obj[capacity];
			for(int i = 0; i < size; i++){
				newArr[i] = c.array[i];
			}
			array = nullptr;
			delete array;
			array = newArr;
		}
		return *this;
	}
    ~Collection(){
		size = 0;
		capacity = 0;
		array = nullptr;
		delete array;
	}
    Collection(Collection&& c): array(c.array), size(c.size), capacity(c.capacity){
		c.array = nullptr;
		delete c.array;
		c.size = 0;
		c.capacity = 0;
	}
    Collection& operator=(Collection&& c){
		if(this != &c){
			array = c.array;
			size = c.size;
			capacity = c.capacity;
			c.array = nullptr;
			delete c.array;
			c.size = 0;
			c.capacity = 0;
		}
		return *this;
	}
    void insert_item(const Obj& sb){
		if(size == capacity){
			resize();
		}
		array[size] = sb;
		size++;
	}
    bool contains(const Obj& sb) const{
		for(int i = 0; i < size; i++){
			if(array[i] == sb){
				return true;
			}
		}
		return false;
	}
    Obj remove_any_item(){
		if(size == 0){
			throw std::invalid_argument("No element in the array!");
		}
		int del = rand()%size;
		Obj random = array[del];
		Obj* newArr = new Obj[capacity];
		for(int i = 0; i < size; i ++){
			if(i < del){
				newArr[i] = array[i];
			}
			else if(i > del){
				newArr[i - 1] = array[i];
			}
		}
		size--;
		array = nullptr;
		delete array;
		array = newArr;
		return random;
	}
    void remove_this_item(const Obj& sb){
		if(size == 0){
			throw std::invalid_argument("No element in the array!");
		}
		int index;
		bool found = false;
		for(int i = 0; i < size; i++){
			if(array[i] == sb){
				index = i;
				found = true;
				break;
			}
		}
		if(found){
			Obj* newArr = new Obj[capacity];
			for(int i = 0; i < size; i ++){
				if(i < index){
					newArr[i] = array[i];
				}
				else if(i > index){
					newArr[i - 1] = array[i];
				}
			}
			size--;
			delete array;
			array = newArr;
		}
	}
    void make_empty(){
		delete array;
		array = nullptr;
		size = 0;
		capacity = 0;
	}
    bool is_empty() const{
		if(size == 0){
			return true;
		}
		return false;
	}
    int total_items() const{
		return size;
	}
    int total_items(F2 s) const{
		int cnt = 0;
		for(int i = 0; i < size; i++){
			if(array[i].get_size() == s){
				cnt++;
			}
		}
		return cnt;
	}
    int total_items(F1 c) const{
		int cnt = 0;
		for(int i = 0; i < size; i++){
			if(array[i].get_color() == c){
				cnt++;
			}
		}
		return cnt;
	}
    void print_items() const{
		for(int i = 0; i < size; i++){
			std::cout << array[i] << std::endl;
		}
	}
    Obj& operator[](int i){
		return array[i];
	}
    const Obj& operator[](int i) const{
		return array[i];
	}
};

template <typename Obj, typename F1, typename F2>
std::ostream& operator<<(std::ostream& os, const Collection<Obj, F1, F2>& c){
	for(int i = 0; i < c.total_items(); i++){
		os << c[i] << std::endl;
	}
	return os;
}

template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2){
	Collection<Obj, F1, F2> c3;
	Obj tmp;
	for(int i = 0; i < c1.total_items(); i++){
	    tmp = c1[i];
		c3.insert_item(Obj(tmp.get_color(), tmp.get_size()));
	}
	for(int i = 0; i < c2.total_items(); i++){
		tmp = c2[i];
		c3.insert_item(Obj(tmp.get_color(), tmp.get_size()));
	}
	return c3;
}

template <typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2){
	Collection<Obj, F1, F2> tmp = c1;
	c1 = c2;
	c2 = tmp;
	tmp.~Collection<Obj, F1, F2>();
}

template <typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort){
	switch(sort){
	  case Sort_choice::bubble_sort:
		for(int i = 0; i < c.total_items(); i++){
			for(int j = 0; j < c.total_items() - i - 1; j++){
				if(c[j].get_size() > c[j + 1].get_size()){
					Obj tmp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = tmp;
				}
			}
		}
		break;
	  case Sort_choice::insertion_sort:
		for(int i = 1; i < c.total_items(); i++){
			Obj tmp = c[i];
			int j = i;
			for(j; (j > 0) && tmp.get_size() < c[j - 1].get_size(); j--){
				c[j] = c[j - 1];
			}
			c[j] = tmp;
		}
		break;
	  case Sort_choice::selection_sort:
		for(int i = 0; i < c.total_items() - 1; i++){
			int min_index = i;
			for(int j = i + 1; j < c.total_items(); j++){
				if(c[j].get_size() < c[min_index].get_size()){
					min_index = j;
				}
			}
			Obj tmp = c[i];
			c[i] = c[min_index];
			c[min_index] = tmp;
		}
		break;
	}
}
#endif