class Conus
{
protected:
	int R, h;
public:
	Conus();
	virtual void EnterParam(); //ввод параметров
	virtual void DisplayParam(); //вывод параметров
	virtual double Area(); //нахождение площади; 
};

class SlicedConus : public Conus
{
	int r;
public:
	SlicedConus();
	virtual void EnterParam();
	virtual void DisplayParam();
	virtual double Area();
};
