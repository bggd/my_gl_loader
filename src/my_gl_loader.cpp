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
