from conans import ConanFile, CMake

class PocoTimerConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "cpprestsdk/2.10.14@bincrafters/stable"
   generators = "cmake", "gcc", "txt"
   default_options = {"cpprestsdk:shared": True, "OpenSSL:shared": True}

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin
      self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin
