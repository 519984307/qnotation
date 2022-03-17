#pragma once

#include <QCoreApplication>
#include <QDebug>
#include <gtest/gtest.h>

namespace QNotationTest {

class SDKGoogleTest : public testing::Test{
public:

    //!
    //! \brief SDKGoogleTest
    //!
    explicit SDKGoogleTest()
    {
    }

    //!
    //! \brief SetUpTestCase
    //!
    static void SetUpTestCase()
    {
    }

    //!
    //! \brief SetUp
    //!
    virtual void SetUp()
    {
    }

    //!
    //! \brief TearDown
    //!
    virtual void TearDown()
    {
    }

    //!
    //! \brief TearDownTestCase
    //!
    static void TearDownTestCase()
    {
    }

public:

};

}


