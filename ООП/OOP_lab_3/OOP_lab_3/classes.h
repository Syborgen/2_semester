class Conus
{
protected:
	int R, h;
public:
	Conus();
	virtual void EnterParam(); //���� ����������
	virtual void DisplayParam(); //����� ����������
	virtual double Area(); //���������� �������; 
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
