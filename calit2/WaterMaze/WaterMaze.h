#ifndef WATERMAZE_PLUGIN_H
#define WATERMAZE_PLUGIN_H


#include <cvrKernel/ComController.h>
#include <cvrKernel/CVRPlugin.h>
#include <cvrKernel/FileHandler.h>
#include <cvrKernel/PluginHelper.h>
#include <cvrKernel/SceneManager.h>
#include <cvrKernel/SceneObject.h>
#include <cvrConfig/ConfigManager.h>

#include <cvrMenu/SubMenu.h>
#include <cvrMenu/MenuRangeValue.h>
#include <cvrMenu/MenuCheckbox.h>
#include <cvrMenu/MenuButton.h>
#include <cvrMenu/MenuText.h>

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/ShapeDrawable>
#include <osg/Switch>
#include <osg/Texture2D>
#include <osgText/Text>
#include <osgDB/ReadFile>

#include <vector>
#include <map>

#include <string.h>
#include <iostream>
#include <stdio.h>

namespace WaterMaze
{

class WaterMaze: public cvr::CVRPlugin, public cvr::MenuCallback
{
public:
    WaterMaze();
    virtual ~WaterMaze();
    static WaterMaze * instance();
    bool init();
    void menuCallback(cvr::MenuItem * item);
    void preFrame();
    bool processEvent(cvr::InteractionEvent * event);
    void load();

protected:
    void loadModels();
    void clear();
    void reset();
    void chooseNewTile();

    float randomFloat(float min, float max)
    {
        if (max < min) return 0;

        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = max - min;
        float r = random * diff;
        return min + r;
    };

    static WaterMaze * _myPtr;

    cvr::SubMenu * _WaterMazeMenu, * _positionMenu, * _detailsMenu;
    cvr::MenuButton * _loadButton, * _clearButton, *_newTileButton;
    cvr::MenuCheckbox * _gridCB, * _wallColorCB, * _shapesCB, * _furnitureCB;
    std::vector<cvr::MenuButton *> _positionButtons;

    osg::ref_ptr<osg::MatrixTransform> _geoRoot; // root of all non-GUI plugin geometry

    osg::ref_ptr<osg::Switch> _gridSwitch, _wallColorSwitch, _wallWhiteSwitch,
        _shapeSwitch, _furnitureSwitch;
    std::map<osg::Vec3, osg::Switch *> _tileSwitches;
    
    std::vector<osg::MatrixTransform *> _tilePositions;

    float widthTile, heightTile, numWidth, numHeight, depth, wallHeight,
        gridWidth, _heightOffset;
    int _hiddenTile;
   
    bool _debug, _loaded; // turns on debug messages to command line

};

};

#endif

