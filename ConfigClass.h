#ifndef __ConfigClass__
#define __ConfigClass__

#include "GUIMyFrame1.h"

class ConfigClass
{
    private:
       /** @brief	MainWindow pointer */
       GUIMyFrame1 *MainWindow;

	    /** @brief	Co-ordinates determinating rectangle */
	    double x0, y0, x1, y1;     

		/** @brief	kat obrotu wykresu */
        double alpha;
        
		/** @brief	true	rotate around center of screen
		*           false	obracamy around center of chart */
        bool ScreenRotate; 
		
		/** @brief	The dX shift relavite to center of the screen */
		double dX;
		
		/** @brief	The dY shift relative to center of the screen */
		double dY;

		/** @brief	Range of x variability  */
		double x_start, x_stop; 

        /** @brief	type of calculated function */
        int F_type;

    public:

        /**********************************************************************************************//**
         * @fn	ConfigClass::ConfigClass(GUIMyFrame1 *wnd);
         *
         * @brief	Constructor
         *
         * @param [in,out]	wnd	If non-null, the window.
         **************************************************************************************************/

        ConfigClass(GUIMyFrame1 *wnd);

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_x_start()
         *
         * @brief	Get x coordinate start
         *
         * @returns	The x coordinate start.
         **************************************************************************************************/

        double Get_x_start() { return x_start; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_x_start(double v)
         *
         * @brief	Sets x coordinate start
         *
         * @param	v	The value.
         **************************************************************************************************/

        void   Set_x_start(double v) { x_start = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_x_stop()
         *
         * @brief	Get x coordinate stop
         *
         * @returns	The x coordinate stop.
         **************************************************************************************************/

        double Get_x_stop() { return x_stop; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_x_stop(double v)
         *
         * @brief	Sets x coordinate stop
         *
         * @param	v	The value.
         **************************************************************************************************/

        void   Set_x_stop(double v) { x_stop = v; };

        /**********************************************************************************************//**
         * @fn	bool ConfigClass::RotateScreenCenter()
         *
         * @brief	Determines if we can rotate screen center
         *
         * @returns	True if it succeeds, false if it fails.
         **************************************************************************************************/

        bool RotateScreenCenter() { return ScreenRotate; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::SetRotateScreen(bool b)
         *
         * @brief	Sets rotate screen
         *
         * @param	b true	rotetes around center of screen 
         * 			  false rotates around the center of chart
         **************************************************************************************************/

        void SetRotateScreen(bool b) { ScreenRotate = b; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_Alpha()
         *
         * @brief	Gets the alpha
         *
         * @returns	The alpha.
         **************************************************************************************************/

        double Get_Alpha() { return alpha; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_Alpha(int a)
         *
         * @brief	Sets an alpha
         *
         * @param	a	An int to process.
         **************************************************************************************************/

        void Set_Alpha(int a) { alpha = a; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_dX()
         *
         * @brief	Gets dX shift
         *
         * @returns	The dX shift.
         **************************************************************************************************/

        double Get_dX() { return dX; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_dX(float v)
         *
         * @brief	Sets dX shift
         *
         * @param	v	The value of x shift.
         **************************************************************************************************/

        void   Set_dX(float v) { dX = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_dY()
         *
         * @brief	Gets dY shift
         *
         * @returns	The dY shift.
         **************************************************************************************************/

        double Get_dY() { return dY;};

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_dY(float v)
         *
         * @brief	Sets dY shift
         *
         * @param	v	The value of y shift.
         **************************************************************************************************/

        void   Set_dY(float v) { dY = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_x0()
         *
         * @brief	Get x0 coordinate 
         *
         * @returns	The x0 coordinate.
         **************************************************************************************************/

        double Get_x0() { return x0; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_x0(float v)
         *
         * @brief	Sets x0 coordinate 
         *
         * @param	v	The value.
         **************************************************************************************************/

        void   Set_x0(float v) { x0 = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_y0()
         *
         * @brief	Get y0 coordinate
         *
         * @returns	The y0 coordinate.
         **************************************************************************************************/

        double Get_y0() { return y0; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_y0(float v)
         *
         * @brief	Sets y0 coordinate 
         *
         * @param	v	The value .
         **************************************************************************************************/

        void   Set_y0(float v) { y0 = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_x1()
         *
         * @brief	Get x1 coordinate
         *
         * @returns	The x1 coordinate.
         **************************************************************************************************/

        double Get_x1() { return x1; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_x1(float v)
         *
         * @brief	Sets x1 coordinate
         *
         * @param	v	The value.
         **************************************************************************************************/

        void   Set_x1(float v) { x1 = v; };

        /**********************************************************************************************//**
         * @fn	double ConfigClass::Get_y1()
         *
         * @brief	Get y1 coordinate
         *
         * @returns	The y1 coordinate.
         **************************************************************************************************/

        double Get_y1() { return y1; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_y1(float v)
         *
         * @brief	Sets y1 coordinate
         *
         * @param	v	The value.
         **************************************************************************************************/

        void   Set_y1(float v) { y1 = v; };

        /**********************************************************************************************//**
         * @fn	int ConfigClass::Get_F_type()
         *
         * @brief	Gets F_type
         *
         * @returns	The F_type.
         **************************************************************************************************/

        int  Get_F_type() { return F_type; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Set_F_type(int i)
         *
         * @brief	Sets F_type
         *
         * @param	i	Zero-based index of the.
         **************************************************************************************************/

        void Set_F_type(int i) { F_type = i; };

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Save(char *filename);
         *
         * @brief	Saves the given file
         *
         * @param [in,out]	filename	If non-null, the filename to save.
         **************************************************************************************************/

        void Save(char *filename);

        /**********************************************************************************************//**
         * @fn	void ConfigClass::Load(char *filename);
         *
         * @brief	Loads the given file
         *
         * @param [in,out]	filename	If non-null, the filename to load.
         **************************************************************************************************/

        void Load(char *filename);

		double scale;
};

#endif
