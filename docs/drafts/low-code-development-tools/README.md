# Low-Code Development Tools

WIP! just notes 

<!-- 2022 -->

## Power apps

Not so responsive - should choose between phone or tabled/desktop


Check flows and how to iterate for example with quartics

Cons
 - responsible ui
 - external sharing
 - performance (if old android phone for example)
 - hard to maintain and extend when complex domain logic, hard to write "good code"
 - sometimes update from microsoft broke the apps
 - not suitable for long term
 - licensing (included for office 365, excel and sharepoint are for free, no premium connectors such as CDS and SQL)
   - for premium, for example 100 users 2 apps = 2000$/m
 - Quick and dirty


## Q&A

- What happened with different environments such as prod and dev, could we have different powers apps?
  - supported check "Extending PowerApps and Flow using Custom Connectors" from links
- When import OpenAPI definition to the power apps, what will happen if later on we update the api definition and reupload the definition file
- Few power apps linked together
  - [Combining Multiple PowerApps Together](https://powerusers.microsoft.com/t5/Building-Power-Apps/Combining-Multiple-PowerApps-Together/m-p/155182#M52478)
  - [PowerApps: Where is the data stored?](https://powerusers.microsoft.com/t5/Power-Apps-Governance-and/PowerApps-Where-is-the-data-stored/m-p/401651#M1594)


### Custom API integration with power apps

- [Connect to Custom API using Custom Connector Power Apps](https://medium.com/@mkbehera01/connect-to-custom-api-using-custom-connector-power-apps-981a86fbd5cf)
- [PowerApps - Custom Connectors - Basic Get](https://www.youtube.com/watch?v=cSzI093-xgk)
- [Consuming an Open API and JSON in Power Apps – 101](https://www.365knowledge.com/2020/05/07/consuming-an-open-api-and-json-in-power-apps-101/)
- [Azure API Management for Power Apps and Power Automate - Open API (Swagger) in Azure API Management](https://powerusers.microsoft.com/t5/Webinars-and-Video-Gallery/Azure-API-Management-for-Power-Apps-and-Power-Automate-Open-API/m-p/818726)
- [App Building with Azure API Management, Functions, Power Apps, and Logic Apps](https://devblogs.microsoft.com/aspnet/app-building-with-azure-api-management-functions-power-apps-and-logic-apps/)
  ASP .NET core API 
- [Create a custom connector from an OpenAPI definition](https://docs.microsoft.com/en-us/connectors/custom-connectors/define-openapi-definition)
  From MS docs
- [How to import APIs to Power Apps using Azure API Management](https://www.youtube.com/watch?v=06CRN18kH1k)
- [Setting up a Custom Connector from an OpenAPI file and utilizing it in PowerApps and Flow](https://carinaclaesson.com/2019/09/06/setting-up-a-custom-connector-from-an-openapi-file-and-utilizing-it-in-powerapps-and-flow/)
- [A Sample OpenAPI/Swagger file for PowerApps](http://www.cleverworkarounds.com/2017/11/13/a-sample-openapiswagger-file-for-powerapps/comment-page-2/)
- [powerapps-register-custom-api.md](https://github.com/uglide/azure-content/blob/master/articles/power-apps/powerapps-register-custom-api.md)
  Some talks about the auth
- [Rest API calls with PowerApps](https://stackoverflow.com/questions/37196287/rest-api-calls-with-powerapps)
- [Live Coding: PowerApps Custom Connectors!](https://www.youtube.com/watch?v=-wQljWG35zM&t=2433s)
- [Using OpenAPI definition to register a custom connector implementing OAuth2](https://powerusers.microsoft.com/t5/Building-Power-Apps/Using-OpenAPI-definition-to-register-a-custom-connector/td-p/327142)
- [custom API connection using JWT that expires](https://powerusers.microsoft.com/t5/Building-Power-Apps/custom-API-connection-using-JWT-that-expires/td-p/353876)
- [Calling an Azure AD secured REST API from PowerApps using Flow](https://www.youtube.com/watch?v=KjshoMqjpKY)
  Maybe this could be the approach for authorization, but then the question is how to going to manage the roles in power apps
- [Extending PowerApps and Flow using Custom Connectors](https://www.youtube.com/watch?v=S4xyb58C1q8)
  Auth with OpenAPI

## Resources

- [Webinar video: 3 great PowerApps examples that can enhance your digital workplace](https://www.youtube.com/watch?v=ajQ_9f7-Qdo)
- [Power Apps Canvas vs Model Driven vs Portals Explained](https://www.youtube.com/watch?v=M_tvnAmHMZY)
- [How to use Microsoft Power Apps](https://www.youtube.com/watch?v=2RzCbd5XgJg)
- [The Top 10 PowerApps Examples](https://www.youtube.com/watch?v=jOAJW7RPw0Y)


## Custom cases

- [Get Started with Power Apps Component Framework (PCF)](https://www.youtube.com/watch?v=5TI61xfMgtQ)
   NodeJS, typescript stack. Support react and angularJS.
   The example from the video is to create a slider widget.
   Shows how to add custom css to the component.
   components store [pcf.gallery](https://pcf.gallery/)


## Data persistance

[What is Common Data Service (CDS) and why it is important for you if you use Power Apps or Power BI?](https://radacad.com/what-is-common-data-service-cds-and-why-it-is-important-for-you-if-you-use-power-apps-or-power-bi#:~:text=Common%20Data%20Service%20is%20a,Platform%20services%20and%20Microsoft%20Dynamics.&text=Common%20Data%20Service%20(CDS)%20is,add%20custom%20entities%20to%20it.)
Common Data Service (CDS) is a database system. this database system stores the data in Azure data lake storage (cloud), and you can work with it through a management portal. CDS is a free database if you are using Power Apps licenses, You can then analyze the data of CDS using Power BI. CDS can be also used as a data warehouse layer using dataflows. In other blog articles, I’ll explain more about that scenario.


## Pricing

[Power Apps Licensing Explained](https://www.youtube.com/watch?v=f_GwhZrwNtI)


## External user use cases

[Introducing PowerApps Portals: powerful low-code websites for external users](https://powerapps.microsoft.com/en-us/blog/introducing-powerapps-portals-powerful-low-code-websites-for-external-users/)
PowerApps Portals, the ability to build low-code, responsive websites which allow external users to interact with the data stored in the Common Data Service.

[Microsoft Power Apps portals | 2020 release wave 1 overview](https://www.youtube.com/watch?v=Bf7Ln6uAwxE)
Talks about basic usage of so called power apps portal
- how to embedded power bi dashboards
- customizing themes (few basic themes and apply custom styles via editor on them)
- can use AAD B2C (kind of AD but more advance, allows ext users. TBC)

[PowerApps Portal vs regular PowerApps](https://stackoverflow.com/questions/59062331/powerapps-portal-vs-regular-powerapps#:~:text=PowerApps%20and%20PowerApps%20portals%20are,having%20very%20much%20in%20common.&text=PowerApps%20Portals%20(previously%20Dynamics%20365,of%20Model%2Ddriven%20PowerApps%20platform)
[Power Apps Canvas vs Model Driven vs Portals Explained](https://www.youtube.com/watch?v=M_tvnAmHMZY)


[Manage Roles in Power Apps Canvas App with Power Automate and SharePoint](https://www.youtube.com/watch?v=N3TENlKHVVI)


## Notes

### When using excel data source
- data should be in table
- should be just values
- no formulas allowed
- no empty space for column names
- in app tables are referenced by table name from the excel file
- other things to consider
  - excel lives in one drive for business
  - file should be shared for user that gonna use the app
  - only one person at a time can use the app (multi connections not supported)
- not suitable for PROD apps


### Power Automate 
- Allows you to build automated workflows to receive notifications, run processes, collect data, and more.


### Licensing/Cost
- Certain data sources like the Microsoft Dataverse or SQL are considered a "premium data source". 
- A premium data source will require each user who uses the app to have a Power Apps Per App Plan or a Power Apps Per User Plan. For more information about licensing


### Power apps types
- Model driven (generated base on data, less control)
  Approach to model-driven app making
  - Modeling business data
  - Defining business processes
  - Composing the app.
- blank canvas (from scratch, but more control)


### Microsoft Dataverse
- Dataverse includes a base set of standard tables that support common business scenarios
- You can also create custom entities specific to your organization and populate them with data that you import from lists in SharePoint, from Excel, or from PowerQuery
- Entities within Dataverse can leverage rich server-side logic and validation to ensure data qualit
  - Business rules: Business rules validate data across multiple columns in a table
  - Business process flows: Business process flows guide users to ensure they enter data consistently and follow the same steps every time. Business process flows are currently supported only for model-driven apps.
  - Workflows: Workflows automate business processes without requiring user interaction.
  - Business logic with code: Business logic supports advanced developer scenarios that extend the application directly through code.
- Security
  - Data in Dataverse is securely stored so that users can see it only if you grant them access. Role-based security, based on TBC
- You can't delete standard tables, but you can hide them
- Table relationships
  - One-to-many relationships: In a one-to-many (1:N) table relationship
  - Many-to-many relationships: In a many-to-many (N:N) table relationship
  Besides defining how records can be related to other records, 1:N table relationships also provide data to address the following questions:
  - When I delete a record, should any records that are related to that record also be deleted?
  - When I assign a record to a new owner, do I also have to assign all related records to the new owner?
  - How can I streamline the data entry process when I create a new related record in the context of an existing  record?
  - How should people who view a record be able to view the related records?
- After a custom table is created, the table type can't be changed.
  - Types of table owners
    - User or team owned
    - Organization-owned
  - Activity tables, default activity tables: Appointment, Email, Fax, Letter, Phone Call, Task
  - Business Rules
    - Set column values
    - Clear column values
    - Set column requirement levels
    - Show or hide columns
    - Enable or disable columns
    - Validate data and show error messages
    - Create business recommendations based on business intelligence.
- You can import data into your Microsoft Dataverse database in bulk from Microsoft Excel or CSV files.
  - You can do a one-time data export from a standard table or a custom table, and you can export data from more than one table at a time. If you export data from more than one table, each table is exported into its own Microsoft CSV file


### Model-driven apps
In canvas apps, the app maker has total control over the app layout. In model-driven apps, on the other hand, much of the layout is determined by the components you add. The emphasis is more on quickly viewing your business data and making decisions instead of on intricate app design.

The approach to making model-driven apps
- Model your business data
  To model business data, you determine what data the app will need and how that data will relate to other data. Metadata means data about data and it defines the structure of the data stored in Microsoft Dataverse.
- Define your business processes
  Defining and enforcing consistent business processes is a key aspect of model-driven app design. Consistent processes help ensure that your app users can focus on their work and not worry about having to remember to perform a set of manual steps.
- Build the app
  After modeling data and defining processes, you build your app by selecting and setting up the components you need in the App Designer.

[Building blocks of model-driven apps](https://docs.microsoft.com/en-us/learn/modules/get-started-with-model-driven-apps-in-powerapps/2-building-blocks-of-model-driven-apps)

[Control security when sharing model-driven apps](https://docs.microsoft.com/en-us/learn/modules/get-started-with-model-driven-apps-in-powerapps/5-control-security-when-sharing-model-driven-apps)
Microsoft Power Apps uses role-based security for sharing. A security role includes privileges that define a set of actions that can be performed in the app. All app users must be assigned to one or more predefined or custom security roles.
Roles can be assigned to individual users or to teams. When a user or a team is assigned to a role, that user or all members of that team are granted the set of privileges associated with the role.

### Power Virtual Agents

Power Virtual Agents are adaptable Artificial Intelligence (AI) chatbots, at your service. They can solve common customer and internal-facing issues automatically, freeing up staff to focus on complex requests and high-value interactions.

When you create chatbots with Power Virtual Agents, you author and edit topics. Topics are discrete conversation paths that, when used together within a single chatbot, allow for users to have a conversation with a chatbot that feels natural and flows appropriately. 

Publishing
With Power Virtual Agents, you can publish chatbots to engage with your customers on multiple platforms or channels. These include live websites, mobile apps, and messaging platforms like **Microsoft Teams** and Facebook.

