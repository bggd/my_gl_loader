using GLenum = uint32_t;
using GLboolean = uint8_t;
using GLbitfield = uint32_t;
using GLvoid = void;
using GLuint = uint32_t;
using GLint = int32_t;
using GLsizei = int32_t;
using GLfloat = float;
using GLclampf = float;

using GLchar = char;

using GLsizeiptr = ptrdiff_t;

#define GL_FALSE 0
#define GL_TRUE 1

#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_SHORT 0x1403
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

#define GL_TRIANGLES 0x0004

#define GL_DEBUG_OUTPUT 0x92E0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242

#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506

#define GL_SCISSOR_TEST 0x0C11

#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_COLOR_BUFFER_BIT 0x00004000

#define GL_BLEND 0x0BE2
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303

#define GL_FUNC_ADD 0x8006

#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31

#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893

#define GL_STREAM_DRAW 0x88E0
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8

#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1

#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601

#define GL_RED 0x1903
#define GL_R8 0x8229
#define GL_ALPHA 0x1906
#define GL_ALPHA8 0x803C
#define GL_RGB 0x1907
#define GL_RGB8 0x8051
#define GL_RGBA 0x1908
#define GL_RGBA8 0x8058

#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_ALIGNMENT 0x0CF5

#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45

#define GL_DEPTH_TEST 0x0B71

#define GL_BACK 0x0405
#define GL_CULL_FACE 0x0B44

typedef void (*MYGLLOADER_DEBUG_PROC) (GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*, void*);

#define MYGLLOADER_GL_DEF(ret, name, ...) ret (*gl##name)(__VA_ARGS__) = NULL;

#define MYGLLOADER_GL_DEF_LIST \
  MYGLLOADER_GL_DEF(void, DebugMessageCallback, MYGLLOADER_DEBUG_PROC, void*) \
  MYGLLOADER_GL_DEF(void, Enable, GLenum) \
  MYGLLOADER_GL_DEF(void, Disable, GLenum) \
  MYGLLOADER_GL_DEF(void, Viewport, GLint, GLint, GLsizei, GLsizei) \
  MYGLLOADER_GL_DEF(void, Scissor, GLint, GLint, GLsizei, GLsizei) \
  MYGLLOADER_GL_DEF(void, ClearColor, GLclampf, GLclampf, GLclampf, GLclampf) \
  MYGLLOADER_GL_DEF(void, Clear, GLbitfield) \
  MYGLLOADER_GL_DEF(void, BlendEquation, GLenum) \
  MYGLLOADER_GL_DEF(void, BlendFunc, GLenum, GLenum) \
  MYGLLOADER_GL_DEF(void, CullFace, GLenum) \
  /* Shader */ \
  MYGLLOADER_GL_DEF(GLuint, CreateProgram, void) \
  MYGLLOADER_GL_DEF(GLuint, CreateShader, GLenum) \
  MYGLLOADER_GL_DEF(void, ShaderSource, GLuint, GLsizei, const GLchar**, const GLint*) \
  MYGLLOADER_GL_DEF(void, CompileShader, GLuint) \
  MYGLLOADER_GL_DEF(void, GetShaderiv, GLuint, GLenum, GLint*) \
  MYGLLOADER_GL_DEF(void, GetShaderInfoLog, GLuint, GLsizei, GLsizei*, GLchar*) \
  MYGLLOADER_GL_DEF(void, BindAttribLocation, GLuint, GLuint, const GLchar*) \
  MYGLLOADER_GL_DEF(void, AttachShader, GLuint, GLuint) \
  MYGLLOADER_GL_DEF(void, LinkProgram, GLuint) \
  MYGLLOADER_GL_DEF(void, GetProgramiv, GLuint, GLenum, GLint*) \
  MYGLLOADER_GL_DEF(void, GetProgramInfoLog, GLuint, GLsizei, GLsizei*, GLchar*) \
  MYGLLOADER_GL_DEF(GLint, GetUniformLocation, GLuint, const GLchar*) \
  MYGLLOADER_GL_DEF(void, UniformMatrix4fv, GLint, GLsizei, GLboolean, const GLfloat*) \
  MYGLLOADER_GL_DEF(void, Uniform1i, GLint, GLint) \
  MYGLLOADER_GL_DEF(void, BindFragDataLocation, GLuint, GLuint, const GLchar*) \
  MYGLLOADER_GL_DEF(void, UseProgram, GLuint) \
  MYGLLOADER_GL_DEF(void, DetachShader, GLuint, GLuint) \
  MYGLLOADER_GL_DEF(void, DeleteShader, GLuint) \
  MYGLLOADER_GL_DEF(void, DeleteProgram, GLuint) \
  /* VAO */ \
  MYGLLOADER_GL_DEF(void, GenVertexArrays, GLsizei, GLuint*) \
  MYGLLOADER_GL_DEF(void, BindVertexArray, GLuint) \
  /* VBO IBO */ \
  MYGLLOADER_GL_DEF(void, GenBuffers, GLsizei, GLuint*) \
  MYGLLOADER_GL_DEF(void, BindBuffer, GLenum, GLuint) \
  MYGLLOADER_GL_DEF(void, EnableVertexAttribArray, GLuint) \
  MYGLLOADER_GL_DEF(void, VertexAttribPointer, GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*) \
  MYGLLOADER_GL_DEF(void, BufferData, GLenum, GLsizeiptr, const GLvoid*, GLenum) \
  MYGLLOADER_GL_DEF(void, DrawArrays, GLenum, GLint, GLsizei) \
  MYGLLOADER_GL_DEF(void, DrawElements, GLenum, GLsizei, GLenum, const GLvoid*) \
  /* Texture */ \
  MYGLLOADER_GL_DEF(void, GenTextures, GLsizei, GLuint*) \
  MYGLLOADER_GL_DEF(void, BindTexture, GLenum, GLuint) \
  MYGLLOADER_GL_DEF(void, TexParameteri, GLenum, GLenum, GLint) \
  MYGLLOADER_GL_DEF(void, PixelStorei, GLenum, GLint) \
  MYGLLOADER_GL_DEF(void, TexImage2D, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*) \
  MYGLLOADER_GL_DEF(void, ActiveTexture, GLenum)


MYGLLOADER_GL_DEF_LIST

#undef MYGLLOADER_GL_DEF

bool my_gl_loader();
