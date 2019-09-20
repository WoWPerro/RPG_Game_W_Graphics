#pragma once
#include <string>


#ifdef DLLObjetos2_Lib
#define DLLObjetos2_API __declspec(dllexport)
#else
#define DLLObjetos2_API __declspec(dllimport)
#endif

class DLLObjetos2_API DLLObjetos
{
public:
	DLLObjetos(int peso);
	DLLObjetos();
	virtual ~DLLObjetos();
	int GetPeso();
	void SetPeso(int peso);
	std::string GetName();
	void SetName(std::string name);
private:
	int _peso;
	std::string _name;
};



