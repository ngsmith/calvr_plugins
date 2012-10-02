#ifndef FP_MICROBE_GRAPH_OBJECT_H
#define FP_MICROBE_GRAPH_OBJECT_H

#include <cvrKernel/TiledWallSceneObject.h>

#include <string>
#include <map>

#include <mysql++/mysql++.h>

#include "GroupedBarGraph.h"

enum SpecialMicrobeGraphType
{
    SMGT_AVERAGE=0,
    SMGT_HEALTHY_AVERAGE,
    SMGT_CROHNS_AVERAGE
};

class MicrobeGraphObject : public cvr::TiledWallSceneObject
{
    public:
        MicrobeGraphObject(mysqlpp::Connection * conn, float width, float height, std::string name, bool navigation, bool movable, bool clip, bool contextMenu, bool showBounds=false);
        virtual ~MicrobeGraphObject();

        bool setGraph(std::string title, int patientid, std::string testLabel);
        bool setSpecialGraph(SpecialMicrobeGraphType smgt);

    protected:
        bool loadGraphData(std::string valueQuery, std::string orderQuery);

        mysqlpp::Connection * _conn;
        
        std::string _graphTitle;
        std::map<std::string, std::vector<std::pair<std::string, float> > > _graphData;
        std::vector<std::string> _graphOrder;

        float _width, _height;

        GroupedBarGraph * _graph;
};

#endif
