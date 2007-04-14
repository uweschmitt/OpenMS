// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework 
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2007 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Marc Sturm $
// --------------------------------------------------------------------------

#ifndef OPENMS_VISUAL_DIALOGS_TOPPVIEWBASEPDP_H
#define OPENMS_VISUAL_DIALOGS_TOPPVIEWBASEPDP_H

#include <OpenMS/config.h>
#include <OpenMS/VISUAL/DIALOGS/PreferencesDialogPage.h>
#include <OpenMS/APPLICATIONS/TOPPViewBase.h>

class QComboBox;
class QLineEdit;
class QRadioButton;
class QCheckBox;

namespace OpenMS
{
	class MultiGradientSelector;
	class ColorSelector;
	
	namespace Internal
	{
		///Preferences dialog page of a TOPPViewBase (internal use only)	
		class TOPPViewBasePDP
			: public PreferencesDialogPage
		{
			Q_OBJECT
			
		public:
			/// Constructor
			TOPPViewBasePDP( TOPPViewBase* manager, QWidget* parent = 0);
			///  Destructor
			virtual ~TOPPViewBasePDP();
			// Docu in base class
			virtual void load();
			// Docu in base class
			virtual void save();
		
		protected slots:
			/// Opens a dialog for browsing through the filesystem
			void browseDefaultPath_();
			/// Opens a dialog for browsing through the filesystem
			void browseTmpPath_();
		
		protected:
			
			//general
			QLineEdit* main_default_path_;
			QLineEdit* main_tmp_path_;
			QSpinBox* recent_files_;
			QComboBox* default_map_view_;
			QComboBox* intensity_cutoff_;
						
			//db
			QLineEdit* db_host_;
			QLineEdit* db_port_;
			QLineEdit* db_name_;
			QLineEdit* db_login_;
			
			//1d
			ColorSelector* peak_color_;
			ColorSelector* high_color_;
			ColorSelector* icon_color_;
			
			//2d
			QComboBox* axis_mapping_2d_;
			QSpinBox* marching_squares_steps_;
			QSpinBox* contour_steps_;
			MultiGradientSelector* dot_gradient_;
			MultiGradientSelector* surface_gradient_;
			
			//3d
			MultiGradientSelector* dot_gradient_3d_;
			QRadioButton* shade_mode_flat_3d_;
			QRadioButton* shade_mode_smooth_3d_;
			QSpinBox* dot_line_width_;
			QComboBox* data_reduction_3d_;
      QSpinBox* reduction_diplay_peaks_3d_;
		};
	
	} //namespace Internal

	
} //namespace OpenMS

#endif //OPENMS_VISUAL_DIALOGS_TOPPVIEWBASEPDP_H

