#pragma once
template<typename T> void SafeDelete(T*& obj) {
	delete obj;
	obj = nullptr;
}