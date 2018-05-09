## Quickstart guide
* Clone this project
* Install 32bit Python 3.4.x into `c:\Python34`
* Download and unpack Boost source: https://www.boost.org/users/history/version_1_66_0.html into `c:\boost`
* Build boost.python libraries - from command prompt in boost folder:
    * Run `bootstrap.bat`
    * Run `b2.exe link=shared --with-python`
* Open this project Visual Studio 2017
    * Set the target to `Release` and `x86`
    * Build solution
* Copy the following files to `c:\Python34` directory
    * `Release\my_module.pyd`
    * `c:\boost\stage\lib\boost_python3-vc141-mt-x32-1_66.dll`  
