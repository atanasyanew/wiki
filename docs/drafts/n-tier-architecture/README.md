# N-thier architecture app

!> Work in process!

TO BE DELETED:

Web
<!-- Web layer, entry point for the applications -->
    - APIs (Entry point)
    - Identity server (security, JWT, etc...)

Data 
<!-- Date access layer -->
    - Data.Models
      - Entities/Models ( Classes represents dbo tables )
      - Mappings ( Entities mappings, used for dbo, keys etc... x has key .... )
      - Migrations ( DBO migrations )
      - Interfaces ( Interfaces for the entities IEntity, IMeasurable, etc... to be implemented from entities )
    - Data.Common ( Repositories, one generic repository should be enoughs for our needs)

Services
<!-- Business logic -->
  - Implementations (implementations against the contacts)
  - Interfaces (contacts)
  - Blob Storage ? (should we add blob storage for additional files ? like zips images etc...)

Tests
<!-- probably gonna skip this one -->
    - Tests.Unit
    - Tests.Integration

Models/DTO
<!-- used to present application models, map domain models to this ones -->
    - DataTransferModels
  
Utilities
    - Common (custom time zone etc...)
    - Infrastructure (CustomExceptions, Enums, Structs, Mappings)


todos:
add nlog for data.common
add implement rest of the methods for the generic repo

base api controller, get the one from reg and add the user functionalities from recomendit, check what is in itg