/***************************************************************************
** MIT License
**
** Copyright (c) 2022 Nikita Vaňků
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
**
******************************************************************************/

#pragma once

#include "SceneProviderRenderer.h"

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QQuickFramebufferObject>
#include <QQuickWindow>

//!
//! \brief The SceneRenderer class
//! SceneRenderer will live on RenderThread
//!
class SceneRenderer : public QQuickFramebufferObject::Renderer, public QOpenGLFunctions {
    Q_DISABLE_COPY(SceneRenderer)
public:
    SceneRenderer();

    virtual void render() override;
    virtual QOpenGLFramebufferObject* createFramebufferObject(const QSize& size) override;
    virtual void synchronize(QQuickFramebufferObject*) override;

private:
    void setupRendering();

private:
    QQuickWindow* m_window = nullptr;

    SceneProviderRenderer* m_sceneProviderRenderer = nullptr;

    QOpenGLBuffer* m_vertexBuffer   = nullptr;
    QOpenGLBuffer* m_elementBuffer  = nullptr;
    QOpenGLShaderProgram* m_program = nullptr;
    QOpenGLVertexArrayObject* m_vao = nullptr;
};
