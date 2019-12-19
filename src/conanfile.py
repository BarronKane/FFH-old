from conans import ConanFile, CMake


class FactorioFrameHost(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "gcc", "txt"
    default_options = {"cpprestsdk:shared": True, "OpenSSL:shared": True}

    def requirements(self):
        self.requires.add("cpprestsdk/2.10.14@bincrafters/stable")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        #cmake.test()
