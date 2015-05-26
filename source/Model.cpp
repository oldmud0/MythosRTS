#include "Model.hpp"
#include "ResManager.hpp"

void Model::modelProcessNode(Model* model, aiNode* node, const aiScene* scene){
    //Process node meshes
    for (GLuint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        model->meshes.push_back(modelProcessMesh(model, mesh, scene));
    }

    //Recurse to children
    for (GLuint i = 0; i < node->mNumChildren; i++) {
        modelProcessNode(model, node->mChildren[i], scene);
    }
}

Mesh Model::modelProcessMesh(Model* model, aiMesh* mesh, const aiScene* scene) {
    std::vector<Vertex>  vertices;
    std::vector<GLuint>  elements;
    std::vector<Texture> textures;
    
    //Process vertex positions, normals and texture coordinates
    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        vec3 pos, normal;
        pos.x    = mesh->mVertices[i].x;
        pos.y    = mesh->mVertices[i].y;
        pos.z    = mesh->mVertices[i].z;

        normal.x = mesh->mNormals [i].x;
        normal.y = mesh->mNormals [i].y;
        normal.z = mesh->mNormals [i].z;

        vertex.pos    = pos;
        vertex.normal = normal;

        //Tex coords? sure, only copy the first set though (we can have up to 8 apparently)
        if (mesh->HasTextureCoords(i)) {
            vec2 texCoords;
            texCoords.x = mesh->mTextureCoords[0][i].x;
            texCoords.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoords = texCoords;
        }
        else {
            //...or just fill it with blanks
            vertex.texCoords = vec2(0.f, 0.f);
        }

        vertices.push_back(vertex);
    }

    //Process indices/elements
    for (GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (GLuint j = 0; j < face.mNumIndices; j++)
            elements.push_back(face.mIndices[j]);
    }

    //Process material, if exists
    if (mesh->mMaterialIndex >= 0) {
        aiMaterial* mat = scene->mMaterials[mesh->mMaterialIndex];
        std::vector<Texture> 
            diffMaps = model->getResManager()->loadMaterialTextures(mat, aiTextureType_DIFFUSE, "tex_diffuse", model->getPath()),
            specMaps = model->getResManager()->loadMaterialTextures(mat, aiTextureType_SPECULAR, "tex_specular", model->getPath());
        textures.insert(textures.end(), diffMaps.begin(), diffMaps.end());
        textures.insert(textures.end(), specMaps.begin(), specMaps.end());
    }

    return Mesh(vertices, elements, textures);
}
