#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);

}

void ChartClass::Set_Range()
	{
	 double xmin=9999.9,xmax=-9999.9,ymin=9999.9,ymax=-9999.9;

	 xmin=cfg->Get_x_start();
	 xmax=cfg->Get_x_stop();

	 y_min=ymin;
	 y_max=ymax;
	 x_min=xmin;
	 x_max=xmax;
}

void ChartClass::Draw(wxDC *dc, int w, int h)
{
	width = w - 20;
	height = h - 20;
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	dc->DrawRectangle(10, 10, w - 20, h - 20);
	dc->SetPen(wxPen(RGB(0, 0, 255)));
	dc->SetClippingRegion(wxRect(10, 10, width, height));
	
	SetTransform();
	DrawAxies(dc);
}

wxPoint ChartClass::point2d(Matrix t, double x1, double y1){
	Vector vector;
	vector.Set(x1, y1);
	vector = t * vector;
	x1 = vector.GetX();
	y1 = vector.GetY();
	return wxPoint(x1, y1);
}

double ChartClass::Get_Y_min()
{
    Set_Range();
    return y_min;
}

double ChartClass::Get_Y_max()
{
    Set_Range();
    return y_max;
}

void ChartClass::SetTransform() {
	Matrix transform; // skalowanie
	transform.data[0][0] = width / (cfg->Get_x1() - cfg->Get_x0());
	transform.data[1][1] = height / (cfg->Get_y1() - cfg->Get_y0()) *(-1);
	transform.data[0][2] = 10- transform.data[0][0] * cfg->Get_x0();
	transform.data[1][2] = 10- transform.data[1][1] * cfg->Get_y1();
	Matrix transform2; // translacja
	transform2.data[0][0] = transform2.data[1][1] = 1;
	transform2.data[0][2] = cfg->Get_dX();
	transform2.data[1][2] = cfg->Get_dY();

	Matrix transform3; //rotacja
	int Rx, Ry;
	if (cfg->RotateScreenCenter()) {
		Rx = width / 2;
		Ry = height / 2;
	}
	else {
		Vector temp;
		temp.Set(0, 0);
		temp = transform * temp;
		Rx = temp.GetX();
		Ry = temp.GetY();
	}
	transform3.data[0][0] = cos(-(cfg->Get_Alpha()) * acos(-1) / 180);
	transform3.data[1][0] = sin(-(cfg->Get_Alpha()) * acos(-1) / 180);
	transform3.data[0][1] = -transform3.data[1][0];
	transform3.data[1][1] = transform3.data[0][0];
	transform3.data[0][2] = Rx * (1 - transform3.data[0][0]) + Ry * transform3.data[1][0];
	transform3.data[1][2] = -Rx * transform3.data[1][0] + Ry * (1 - transform3.data[0][0]);

	tr = transform3 * transform2 * transform;
}

void ChartClass::DrawAxies(wxDC *dc) {
	double *x1=new double, *x2 = new double, *y1 = new double, *y2 = new double;
	Set_Range();

	//XAxis
	*x1 = x_min; *x2 = x_max-1; *y1 = 0; *y2 = 0;
	dc->DrawLine(point2d(tr,*x1,*y1),point2d(tr, *x2,*y2)); 

	//YAxis
	*x1 = 0; *x2 = 0; *y1 = y_min; *y2 = y_max;
	dc->DrawLine(point2d(tr,*x1, *y1), point2d(tr,*x2, *y2));

	delete x1;
	delete x2;
	delete y1;
	delete y2;
}