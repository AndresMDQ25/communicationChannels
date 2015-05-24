#ifndef IMAGEANALYZER_H
#define IMAGEANALYZER_H

#include <QString>
#include <QImage>
#include <QDebug>
#include <QRgb>
#include <QColor>

class ImageAnalyzer
{
public:
    ImageAnalyzer();
    void start(QString filePath);
    QVector<QString> getColors();

private:
    QImage image;
    QVector<QString> colors;
};

#endif // IMAGEANALYZER_H
