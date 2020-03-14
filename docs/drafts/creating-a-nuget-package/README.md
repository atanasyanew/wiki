# Creating a nuget package

!> Work in process!

nuget.exe in solution dir


cmd
```
nuget spec 
```
this will generate Package.nuspec

```
<?xml version="1.0"?>
<package >
  <metadata>
    <id>Cashcloud.co.za.api</id>
    <version>1.0.0</version>
    <authors>AtanasYanev</authors>
    <owners>CompanyName</owners>
    <licenseUrl>http://LICENSE_URL_HERE_OR_DELETE_THIS_LINE</licenseUrl>
    <projectUrl>http://PROJECT_URL_HERE_OR_DELETE_THIS_LINE</projectUrl>
    <iconUrl>http://ICON_URL_HERE_OR_DELETE_THIS_LINE</iconUrl>
    <requireLicenseAcceptance>false</requireLicenseAcceptance>
    <description>http://cashcloudmobileapi-env.pp6mzyrcqs.eu-west-1.elasticbeanstalk.com/swagger</description>
    <releaseNotes></releaseNotes>
    <copyright>Copyright 2018</copyright>
    <tags> </tags>
    <dependencies>
      <dependency id="SampleDependency" version="1.0" />
    </dependencies>
  </metadata>
  <files>
    <file src="src\Cashcloud.co.za.api\bin\Debug\netcoreapp2.0\Cashcloud.co.za.api.dll" target="lib"></file>    
  </files>
</package>

```


rebuild the proj


cmd
```
nuget pack Package.nuspec
```

from vs, in search panel "tools -> options -> nuget package manager" and add the folder where the generated nuget is stored, so you can add it from the package manager.