#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string filename, GLenum filter)
{
    int width, height, channelAmt;
    unsigned char* texData = stbi_load(filename.c_str(), &width, &height, &channelAmt, 0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

    if(!texData)
    {
        std::cout << "Failed to load texture: " << filename << std::endl;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, NULL, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(texData);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::GetTexture()
{
    return texture;
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::Clear()
{
    glDeleteTextures(1, &texture);
}

Texture::~Texture()
{

}
