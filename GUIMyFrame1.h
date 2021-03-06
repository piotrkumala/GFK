#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <memory>

class ChartClass;
class ConfigClass;

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void MainFormClose( wxCloseEvent& event );
		void WxPanel_Repaint( wxUpdateUIEvent& event );
		void ChangeChartColor( wxCommandEvent& event );
		void ChangePointColor( wxCommandEvent& event );
		void ChangeScale( wxScrollEvent& event );
		void ChangePointSize( wxCommandEvent& event );
		void AddError( wxCommandEvent& event );
		void ChangeRegresionType( wxCommandEvent& event );
		void OpenFormFile( wxCommandEvent& event );
		void OpenFromKeyboard( wxCommandEvent& event );
		void Save( wxCommandEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
		
		//// end generated class members

		/**********************************************************************************************//**
		 * @fn	void GUIMyFrame1::Repaint();
		 *
		 * @brief	Repaints this object
		 **************************************************************************************************/

		void Repaint();

		/**********************************************************************************************//**
		 * @fn	void GUIMyFrame1::UpdateControls();
		 *
		 * @brief	Updates the controls
		 **************************************************************************************************/

		void UpdateControls();

		/**********************************************************************************************//**
		 * @fn	GUIMyFrame1::~GUIMyFrame1();
		 *
		 * @brief	Destructor
		 **************************************************************************************************/

		~GUIMyFrame1();
		/** @brief	The configuration */
		std::shared_ptr<ConfigClass> cfg;
		/** @brief	The buffer */
		wxBitmap m_buffer;
		/** @brief	The image */
		wxImage m_image;
		/** @brief	The chart */
		ChartClass* chart;


};

#endif // __GUIMyFrame1__
