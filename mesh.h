#ifndef MESH_H
#define MESH_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"

#include <string>
#include <vector>
using namespace std;

#define MAX_BONE_INFLUENCE 4

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    //bone indexes which will influence this vertex
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    //weights from each bone
    float m_Weights[MAX_BONE_INFLUENCE];
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};


class Mesh {
public:
    // mesh Data
    vector<Vertex>       vertices;
    vector<unsigned int> indices;
    vector<Texture>      textures;
    QOpenGLVertexArrayObject VAO;

    // constructor
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
    {
        m_glFunc = QOpenGLFunctions();
        m_glFunc.initializeOpenGLFunctions();

        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;

        setupMesh();
    }

    Mesh(const Mesh& other) {
        m_glFunc = QOpenGLFunctions();
        m_glFunc.initializeOpenGLFunctions();

        this->vertices = other.vertices;
        this->indices = other.indices;
        this->textures = other.textures;

        setupMesh();
    }

    // render the mesh
    void Draw(Shader &shader)
    {
        // bind appropriate textures
        unsigned int diffuseNr  = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr   = 1;
        unsigned int heightNr   = 1;
        for(unsigned int i = 0; i < textures.size(); i++)
        {
            m_glFunc.glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
            // retrieve texture number (the N in diffuse_textureN)
            string number;
            string name = textures[i].type;
            if(name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if(name == "texture_specular")
                number = std::to_string(specularNr++); // transfer unsigned int to string
            else if(name == "texture_normal")
                number = std::to_string(normalNr++); // transfer unsigned int to string
            else if(name == "texture_height")
                number = std::to_string(heightNr++); // transfer unsigned int to string

            // now set the sampler to the correct texture unit
            m_glFunc.glUniform1i(m_glFunc.glGetUniformLocation(shader.ID, (name + number).c_str()), i);
            // and finally bind the texture
            m_glFunc.glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }

        // draw mesh
        VAO.bind();
        m_glFunc.glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        VAO.release();

        // always good practice to set everything back to defaults once configured.
        m_glFunc.glActiveTexture(GL_TEXTURE0);
    }

private:
    // render data
    unsigned int VBO, EBO;

    // initializes all the buffer objects/arrays
    void setupMesh()
    {
        // create buffers/arrays
        VAO.create();
        m_glFunc.glGenBuffers(1, &VBO);
        m_glFunc.glGenBuffers(1, &EBO);

        VAO.bind();
        // load data into vertex buffers
        m_glFunc.glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        m_glFunc.glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        m_glFunc.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        m_glFunc.glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        m_glFunc.glEnableVertexAttribArray(0);
        m_glFunc.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        m_glFunc.glEnableVertexAttribArray(1);
        m_glFunc.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        // vertex texture coords
        m_glFunc.glEnableVertexAttribArray(2);
        m_glFunc.glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
        // vertex tangent
        m_glFunc.glEnableVertexAttribArray(3);
        m_glFunc.glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
        // vertex bitangent
        m_glFunc.glEnableVertexAttribArray(4);
        m_glFunc.glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
        // ids
        m_glFunc.glEnableVertexAttribArray(5);
        m_glFunc.glVertexAttribPointer(5, 4, GL_INT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));

        // weights
        m_glFunc.glEnableVertexAttribArray(6);
        m_glFunc.glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
        VAO.release();
    }

    QOpenGLFunctions m_glFunc;
};
#endif
