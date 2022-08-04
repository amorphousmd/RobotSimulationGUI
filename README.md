# RobotSimulationGUI
![forward](https://user-images.githubusercontent.com/20887245/182783840-a8f7cf3e-092f-4740-be0a-017bbd83d65a.gif)  
![inverse](https://user-images.githubusercontent.com/20887245/182783852-413b5ce0-8422-4b0f-93aa-7698e692fc0e.gif)  

Requirements: Qt5, OpenGL3.3, Assimp.  
Special thanks to https://github.com/khuong-nv for the STL files.  

![2022-07-29 11_04_20-](https://user-images.githubusercontent.com/20887245/181680687-385754c2-e0f5-4bdb-84b4-4acd6ecaae86.png)

If you run into this error just press OK  
![c54fe9c1-5eaa-4474-b7a8-dc64fa0e9675](https://user-images.githubusercontent.com/20887245/182780728-17298e2e-4892-4c62-9d0d-8ca811b08594.png)

Select the build kits like below (Important)  
![ec14cbfe-1f6c-4ceb-9cb9-71fa000186c5](https://user-images.githubusercontent.com/20887245/182781008-fbedbc9d-59a2-4326-bbd1-ff125afca15c.png)

Then build the project  
If you run into the missing dll error like below
![6eb6ef46-b6f5-42ed-b682-57be6f80a525](https://user-images.githubusercontent.com/20887245/182781177-d6eda629-3847-4c70-9d89-1105d84be83f.png)

You need to copy the Assimp64.dll from the install directory.  
The path should be: C:\Program Files\Assimp\bin\x64 if you installed Assimp as default path
![5a9838f7-f03c-4d35-b3ab-28e3eaac47e7](https://user-images.githubusercontent.com/20887245/182782887-16e04c57-7406-41aa-9f67-351f4ef016f6.png)

If you had installed in another directory, you will need to edit the .pro file in Qt  
![2022-08-04 13_40_47-Display3DModel pro @ Display3DModel - Qt Creator](https://user-images.githubusercontent.com/20887245/182782832-82383f54-88af-4462-82cf-ed71f2d6cb6e.png)

You then paste the file into your debug folder (after you've built the project), the result should look like this  
![4532392d-a7a5-4b6d-89a9-4652ad9defa2](https://user-images.githubusercontent.com/20887245/182783309-5fb45218-acc0-4343-88fe-9e2766a5b454.png)
And you should be able to run the project normally now  