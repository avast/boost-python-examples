## Quickstart guide
* Clone this project
* Install Python 3.4.x into `c:\Python34`
* Download and unpack Boost source: https://www.boost.org/users/history/version_1_66_0.html into `c:\boost`
* Build boost.python libraries - from command prompt in boost folder:
    * Run `bootstrap.bat`
    * Run `b2.exe link=shared --with-python`
* Open this project Visual Studio 2017 
* Build solution
* Copy PYD module and Boost DLL to `PYTHONPATH` to make it importable from Python
