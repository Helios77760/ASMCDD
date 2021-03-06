//
// Created by drake on 23/10/19.
//

#ifndef DISKSPROJECT_SHADER_H
#define DISKSPROJECT_SHADER_H

#include <GL/glew.h>
#include <string>
#include <vector>
#include <memory>

/**
 * This class manages a shader for OpenGL
 */
class Shader{
public:
    Shader(GLenum type, std::string const & filename);
    ~Shader();
    bool compile();
    Shader& operator=(const Shader &s)=delete;
    bool operator==(const Shader &s);
    static std::shared_ptr<Shader>& createShader(GLenum type, const std::string & filename);
    static std::vector<std::shared_ptr<Shader>>& getShaderList();


    [[nodiscard]] GLuint getId() const;
    [[nodiscard]] GLint getCompileStatus() const;
    [[nodiscard]] const std::string &getFilename() const;
    [[nodiscard]] GLenum getType() const;
    void setFilename(const std::string &_filename);
    void replace_in_shader(const std::string & pattern, const std::string & replace);
    void clear_replacements();

    static bool compileAll();


private:
    static std::vector<std::shared_ptr<Shader>> shaderList;
    std::vector<std::pair<std::string, std::string>> values_to_replace;
    GLuint id;
    GLint compile_status;
    std::string filename;
    GLenum type;

};

#endif //DISKSPROJECT_SHADER_H
