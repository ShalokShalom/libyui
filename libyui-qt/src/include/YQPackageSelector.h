/*---------------------------------------------------------------------\
|								       |
|		       __   __	  ____ _____ ____		       |
|		       \ \ / /_ _/ ___|_   _|___ \		       |
|			\ V / _` \___ \ | |   __) |		       |
|			 | | (_| |___) || |  / __/		       |
|			 |_|\__,_|____/ |_| |_____|		       |
|								       |
|				core system			       |
|							 (C) SuSE GmbH |
\----------------------------------------------------------------------/

  File:	      YQPackageSelector.h

  Author:     Stefan Hundhammer <sh@suse.de>

/-*/

// -*- c++ -*-

#ifndef YQPackageSelector_h
#define YQPackageSelector_h

#include <qvbox.h>
#include <ycp/YCPString.h>

#include "YPackageSelector.h"


class YUIQt;
class QLabel;
class QComboBox;
class QSplitter;
class QListView;
class QTabWidget;
class QProgressBar;
class QCheckBox;
class QY2ComboTabWidget;
class YQPkgList;
class YQPkgRpmGroupTagsFilterView;
class YQPkgDescriptionView;
class YQPkgTechnicalDetailsView;
class YQPkgSelectionsFilterView;
class YQPkgSelList;


class YQPackageSelector : public QVBox, public YPackageSelector
{
    Q_OBJECT

public:

    YQPackageSelector( YUIQt *yuiqt, QWidget *parent, YWidgetOpt &opt );

    /**
     * Inherited from YWidget: Sets the enabled state of the
     * widget. All new widgets are enabled per definition. Only
     * enabled widgets can take user input.
     **/
    void setEnabling(bool enabled);

    /**
     * Minimum size the widget should have to make it look and feel
     * nice.
     * @dim Dimension, either YD_HORIZ or YD_VERT
     **/
    long nicesize(YUIDimension dim);

    /**
     * Sets the new size of the widget.
     **/
    void setSize(long newwidth, long newheight);

    /**
     * Accept the keyboard focus.
     **/
    virtual bool setKeyboardFocus();


public slots:

    /**
     * Close processing - return back to UserInput()
     **/
    void close();

    /**
     * Display online help
     **/
    void help();

    // FIXME
    void preAlphaWarning();

    
signals:

    /**
     * Emitted once (!) when the dialog is about to be shown, when all widgets
     * are created and all signal/slot connections are set up - when it makes
     * sense to load data.
     **/
    void loadData();

    
protected:

    // Layout methods - create and layout widgets

    void basicLayout();

    void layoutLeftPane		( QWidget * parent );
    void layoutFilters		( QWidget * parent );
    void layoutDiskSpaceSummary	( QWidget * parent );
    void layoutRightPane	( QWidget * parent );
    void layoutPkgList		( QWidget * parent );
    void layoutDetailsViews	( QWidget * parent );
    void layoutButtons		( QWidget * parent );
    void layoutMenuBar		( QWidget * parent );

    void makeConnections();
    

    // Data members

    /**
     * Pointer to the ui
     */
    YUIQt *yuiqt;


    QWidget			* _leftPane;
    QY2ComboTabWidget		* _filters;
    QProgressBar		* _diskSpace;
    YQPkgList			* _pkgList;
    QTabWidget			* _detailsViews;
    YQPkgDescriptionView	* _pkgDescriptionView;
    YQPkgTechnicalDetailsView	* _pkgTechnicalDetailsView;
    QCheckBox			* _autoDependenciesCheckBox;
    YQPkgRpmGroupTagsFilterView * _rpmGroupTagsFilterView;
    YQPkgSelectionsFilterView	* _selectionsFilterView;
    YQPkgSelList		* _selList;
};

#endif // YQPackageSelector_h
