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
    int getHeight() const;
    int getWidth() const;
private:
    QImage image;
    QVector<QString> colors;
    int height;
    int width;
};

#endif // IMAGEANALYZER_H
