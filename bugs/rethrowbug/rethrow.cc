
extern "C" __attribute__((dllexport)) int boom()
{
  try{ throw; } catch(...){ return 1;}
  return 2;
}

