/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_PARAMETERBUILDER_H
#define NSU_PARAMETERBUILDER_H

#include <QVariantMap>

#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT ParameterBuilderPrivate;

        /**
         * @brief Constructs a QVariantMap from the provided arguments.
         *
         * This class is used as a shortcut for creating and initializing a
         * QVariantMap. When using a method that requires a QVariantMap
         * reference as a parameter, simply create an anonymous instance of this
         * class and use the << operator to concatenate pairs of QVariants.
         *
         * To construct a QVariantMap for a single key/value, use the
         * constructor:
         *
         * \code
         * ParameterBuilder("key", 12345);
         * \endcode
         *
         * To construct a QVariantMap with multiple key/value pairs, use the
         * empty constructor in conjunction with the << operator:
         *
         * \code
         * ParameterBuilder() << "key1" << "value1"
         *                    << "key2" << "value2";
         * \endcode
         */
        class NSU_EXPORT ParameterBuilder : public QVariantMap
        {
            public:

                /**
                 * @brief Creates an empty ParameterBuilder
                 */
                ParameterBuilder();

                /**
                 * @brief Creates a ParameterBuilder and inserts the specified item
                 * @param key the key for the item to insert
                 * @param value the value for the item to insert
                 */
                ParameterBuilder(QString key, QVariant value);

                /**
                 * @brief Destroys the object
                 */
                virtual ~ParameterBuilder();

                /**
                 * @brief Allows values to be inserted into the map
                 * @param parameter alternating key or value
                 * @return a reference to the current builder
                 */
                ParameterBuilder & operator<<(const QVariant & parameter);

            private:

                ParameterBuilderPrivate * const d;

                // Copy is disabled due to the pointer above
                Q_DISABLE_COPY(ParameterBuilder)
        };
    }
}

#endif // NSU_PARAMETERBUILDER_H
