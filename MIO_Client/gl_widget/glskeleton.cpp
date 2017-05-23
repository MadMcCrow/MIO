#include "glskeleton.h"

GLSkeleton::GLSkeleton()
{
    m_model.clear();
    QMatrix4x4 M;
    M.setToIdentity();
    M.translate(2,0,0);
    m_model.push_back(M);
    M.setToIdentity();
    M.translate(-2,0,0);
    m_model.push_back(M);
}

GLSkeleton::GLSkeleton(const GLSkeleton &source)
{
 m_model = source.m_model;
}
