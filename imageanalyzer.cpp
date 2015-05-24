#include "imageanalyzer.h"

ImageAnalyzer::ImageAnalyzer()
{
}

void ImageAnalyzer::start(QString filePath)
{
    this->colors.clear();
    if (image.load(filePath)) {
        int height = image.height();
        int width = image.width();
        QVector<QString> colors;
        for (int x=0; x < height; x++) {
            for (int y=0; y < width; y++) {
                QString value = ((QColor)image.pixel(y, x)).name();
                if(!colors.contains(value))
                    colors.push_back(value);
            }
        }
        this->colors = colors;
    }
}


QVector<QString> ImageAnalyzer::getColors()
{
    return this->colors;
}
