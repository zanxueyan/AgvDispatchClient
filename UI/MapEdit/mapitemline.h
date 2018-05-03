﻿#ifndef MAPITEMLINE_H
#define MAPITEMLINE_H

#include <QObject>
#include <QGraphicsLineItem>
#include "../../data/onemap.h"

class MapItemStation;

class MapItemLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    explicit MapItemLine(MapItemStation *_startStation, MapItemStation *_endStation, MapPath *_path, QGraphicsItem *parent = nullptr,QObject *_parent = nullptr);
    enum { Type = UserType + 23 };
    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return Type;
    }

    MapItemStation *getStartStation(){return startStation;}

    MapItemStation *getEndStation(){return endStation;}

    MapPath *getPath(){return path;}

    void my_update();
signals:
    void sig_propertyChanged(MapSpirit *spirit);
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
public:
    MapItemStation *startStation;
    MapItemStation *endStation;
    MapPath *path;
};

#endif // MAPITEMLINE_H
