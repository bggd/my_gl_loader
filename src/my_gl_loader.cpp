#ifdef MYGLLOADER_DEBUG

#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B

static void
my_gl_loader_debug_output_cb(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, void* userParam)
{
  // code from https://learnopengl.com/#!In-Practice/Debugging

  // ignore non-significant error/warning codes
  if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

  fprintf(stderr, "---------------\n");
  fprintf(stderr, "Debug message (%d):%s\n", id, message);

  switch (source)
  {
    case GL_DEBUG_SOURCE_API:             fprintf(stderr, "Source: API\n"); break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   fprintf(stderr, "Source: Window System\n"); break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: fprintf(stderr, "Source: Shader Compiler\n"); break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:     fprintf(stderr, "Source: Third Party\n"); break;
    case GL_DEBUG_SOURCE_APPLICATION:     fprintf(stderr, "Source: Application\n"); break;
    case GL_DEBUG_SOURCE_OTHER:           fprintf(stderr, "Source: Other\n"); break;
  }

  switch (type)
  {
    case GL_DEBUG_TYPE_ERROR:               fprintf(stderr, "Type: Error\n"); break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: fprintf(stderr, "Type: Deprecated Behaviour\n"); break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  fprintf(stderr, "Type: Undefined Behaviour\n"); break;
    case GL_DEBUG_TYPE_PORTABILITY:         fprintf(stderr, "Type: Portability\n"); break;
    case GL_DEBUG_TYPE_PERFORMANCE:         fprintf(stderr, "Type: Performance\n"); break;
    case GL_DEBUG_TYPE_MARKER:              fprintf(stderr, "Type: Marker\n"); break;
    case GL_DEBUG_TYPE_PUSH_GROUP:          fprintf(stderr, "Type: Push Group\n"); break;
    case GL_DEBUG_TYPE_POP_GROUP:           fprintf(stderr, "Type: Pop Group\n"); break;
    case GL_DEBUG_TYPE_OTHER:               fprintf(stderr, "Type: Other\n"); break;
  }

  switch (severity)
  {
    case GL_DEBUG_SEVERITY_HIGH:         fprintf(stderr, "Severity: high\n"); break;
    case GL_DEBUG_SEVERITY_MEDIUM:       fprintf(stderr, "Severity: medium\n"); break;
    case GL_DEBUG_SEVERITY_LOW:          fprintf(stderr, "Severity: low\n"); break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: fprintf(stderr, "Severity: notification\n"); break;
  }

  fprintf(stderr, "\n");

  abort();
}

#endif

bool my_gl_loader()
{
#define MYGLLOADER_GL_DEF(ret, name, ...) \
  gl##name = (decltype(gl##name))SDL_GL_GetProcAddress("gl"#name); \
  if (gl##name == NULL) { return false; }

  MYGLLOADER_GL_DEF_LIST
  MYGLLOADER_GL_DEF_LIST_DEBUG

#undef MYGLLOADER_GL_DEF

  return true;
}

void my_gl_loader_enable_debug_output()
{
#ifdef MYGLLOADER_DEBUG
  glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(my_gl_loader_debug_output_cb, NULL);
#endif
}
