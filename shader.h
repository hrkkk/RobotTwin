#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;

    Shader() {}
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* vertexPath, const char* fragmentPath)
    {
        m_openGLFunctions = new QOpenGLFunctions();
        m_openGLFunctions->initializeOpenGLFunctions();

        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;

        std::ifstream vertexReader(vertexPath);
        std::ifstream fragmentReader(fragmentPath);

        if (vertexReader.is_open()) {
            std::string line;
            while (std::getline(vertexReader, line)) {
                vertexCode.append(line + '\n');
            }
            vertexReader.close();
        }

        if (fragmentReader.is_open()) {
            std::string line;
            while (std::getline(fragmentReader, line)) {
                fragmentCode.append(line + '\n');
            }
            fragmentReader.close();
        }

        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        unsigned int vertex, fragment;
        // vertex shader
        vertex = m_openGLFunctions->glCreateShader(GL_VERTEX_SHADER);
        m_openGLFunctions->glShaderSource(vertex, 1, &vShaderCode, NULL);
        m_openGLFunctions->glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = m_openGLFunctions->glCreateShader(GL_FRAGMENT_SHADER);
        m_openGLFunctions->glShaderSource(fragment, 1, &fShaderCode, NULL);
        m_openGLFunctions->glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        ID = m_openGLFunctions->glCreateProgram();
        m_openGLFunctions->glAttachShader(ID, vertex);
        m_openGLFunctions->glAttachShader(ID, fragment);
        m_openGLFunctions->glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        m_openGLFunctions->glDeleteShader(vertex);
        m_openGLFunctions->glDeleteShader(fragment);

    }
    // activate the shader
    // ------------------------------------------------------------------------
    void use() const
    {
        m_openGLFunctions->glUseProgram(ID);
    }
    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const
    {
        m_openGLFunctions->glUniform1i(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    {
        m_openGLFunctions->glUniform1i(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    {
        m_openGLFunctions->glUniform1f(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const
    {
        m_openGLFunctions->glUniform2fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec2(const std::string &name, float x, float y) const
    {
        m_openGLFunctions->glUniform2f(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), x, y);
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    {
        m_openGLFunctions->glUniform3fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    {
        m_openGLFunctions->glUniform3f(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    {
        m_openGLFunctions->glUniform4fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    {
        m_openGLFunctions->glUniform4f(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        m_openGLFunctions->glUniformMatrix2fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        m_openGLFunctions->glUniformMatrix3fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        m_openGLFunctions->glUniformMatrix4fv(m_openGLFunctions->glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            m_openGLFunctions->glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                m_openGLFunctions->glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            m_openGLFunctions->glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                m_openGLFunctions->glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }

    QOpenGLFunctions* m_openGLFunctions;
};
#endif
