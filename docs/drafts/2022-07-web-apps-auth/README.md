# Web applications auth

- [Web applications auth](#web-applications-auth)
  - [Others](#others)
  - [Common](#common)
  - [Basic Authentication](#basic-authentication)
  - [OAuth](#oauth)
    - [Terminologies/vocabulary](#terminologiesvocabulary)
    - [Workflow](#workflow)
    - [OpenId connect](#openid-connect)
  - [SAML](#saml)
    - [SAML Terms](#saml-terms)
    - [Provisioning](#provisioning)
    - [Best practices](#best-practices)
      - [Most common week points:](#most-common-week-points)
      - [Best practices](#best-practices-1)
    - [SSO](#sso)
  - [Duende](#duende)

https://medium.com/@vivekmadurai/different-ways-to-authenticate-a-web-application-e8f3875c254a
https://stackoverflow.com/questions/58339005/what-is-the-most-common-way-to-authenticate-a-modern-web-app


what types of authentication and authorization are most used

check - proof key for code exchange (Oauth related)

OWIN - where is in the picture of all

## Others

Asymmetric Encryption - Simply explained
https://www.youtube.com/watch?v=AQDCe585Lnc

<!-- криптира се с публичния ключ но може да се декриптира само с прайвит ключа -->

## Common

Authentication fundamentals: The basics | Azure Active Directory
https://www.youtube.com/watch?v=fbSVgC8nGz4 - good talk about concepts

Basic Auth, SAML, Keys, OAuth, JWT and Tokens
https://www.youtube.com/watch?v=ew5ycTMELJI

An Illustrated Guide to OAuth and OpenID Connect
https://www.youtube.com/watch?v=t18YB3xDfXI

Authentication on the Web (Sessions, Cookies, JWT, localStorage, and more)
https://www.youtube.com/watch?v=2PPSXonhIck


## Basic Authentication

https://www.youtube.com/watch?v=rhi1eIjSbvk

need to use TLS

## OAuth

OAuth: Past, Present, and Future | Developer Day 2021
https://www.youtube.com/watch?v=LopE3t0-Ak8


OAuth 2.0 access tokens explained
https://www.youtube.com/watch?v=BNEoKexlmA4


What is OAuth and why does it matter? - OAuth in Five Minutes
https://www.youtube.com/watch?v=KT8ybowdyr0

What's the difference between Confidential and Public clients? - OAuth in Five Minutes
https://www.youtube.com/watch?v=5cQNwifDq1U&list=PLshTZo9V1-aG5eK1EQuRUdKqIMXpgQM5O

How to Hack OAuth
https://www.youtube.com/watch?v=aU9RsE4fcRM

OAuth 2.0 is a security standard where you give one application permission to access your data in another application.
Instead of giving them your username and password, you can essentially give one app a key that gives them specific permission to access your data or do things on your behalf in another application.
The steps to grant permission or consent are often referred to as authorization or event delegated authorization.
You authorize one application to access your data or use features in another application on your behalf without giving them your password, whats more you can take back that key whenever you wish.

As an example:
WIP!

OAuth steps:
WIP!

### Terminologies/vocabulary

Resource owner
Owner of the indentity, data and any actions that can be performed with your accoutns

Client
The client is the application that wants to access data or perform actions on behalf of you the resource owner

Authorization server
Is the application that knows the resource owner where the resource owner alredy has an account.
The resource server is the application interface or an API or the service the client wants to use on behalf of the resource owner.
Sometimes authorization server and the resouce server are the same server however, there are cases they will not be the same server or even part of the same organization, for example the authorization server might be athird party service the resource server trusts.

Redirect URL
The URL that the autroization server will redirect the resource owner back to after granting permission to the client.
This is sometimes reffered to as the callback url

Response type
The type of information the client expects to recieve the most common response type is code where the client expects to receive an authorization code

Scope
The granular permissions the client wants, such as access to data or to perform actions.
For example - read contancts, create contact, read profile, etc..

Consent
The authorization server takes the Scopes the client is requesting and verifies with the resource owner whether or not they want to give the client permission
For example - Do you want to allow "xyz application" to "list of scopes"

Client Id
This Id is used to identify the client with the authorization server.
There is also a client secret - this is a secret password that only the client and the authorization server know, this allows them to securely share information privately behind the scenes.

Authorization code
Short-lived temporary code the authorization server sends back to the client, the client then privately sends the authorization code back to the authorization server along with the client secred in exchange for an access token.

Access token
Is the key that the client will use from that point foward to communicate with the resource server.
This is like a key or key card that gives the client permission to request data or perform actions with the resource server on your behalf

### Workflow

You (the resource owner) want to allow the application for example WIP! (the client) to access your contacts.
The client redirects your browser to the authorization server and includes with the request the client Id, redirect URL, response type, and one or more scopes it needs
The authorization server verifies who you are and if necessary prompts for a login 
the authorization server then presents you with a form based on the scopes requested by the client
and you have the opportunity to grant or deny permission 
the authorization server redirects back to the client using the defined redirect url along with a temporary
authorization code 
the client then contacts authorization server directly it does not use the resource owners browser and securly sends its client id, client secret and the authorization code 
The authorization server verifies the data and responds with an access token
The access token is a value the client doesnt understand as far as the client is concerned the access token is just a string of gibberish 
The client can use the token to send request to the resource server
For example:
    the client says here's an access token I would like the contacts associeted with the resource owner of this token the resource server verifies the access token and if valid responds with the requested contacts  

### OpenId connect

OAuth 2.0 is design only for authorization, granting access to data and features from one application to another
is like giving an application (the client) a key that key is useful, but it doesn't tell the client who you are or anything about you.

OpenID connect sometimes referred to as OIDC is thin layer that sits on top of OAuth 2.0 that adds functionality around login and profile information about the person who is logged in 
Instead of a key  OIDC is like giving the client application a badge.
The badge not only gives the client specific permissions is also provides some basic information about who you are.
Where OAuth enables authorization from one app to another OIDC enables a client to establish a login session often referred to as authentication as well as to gain information about the logged in person (the resource owner) which is often called indentity.
When authorization server supports OIDC it is sometimes called an ``identity provider`` since it provides information about the resource owner back to the client

OpenId connect enables scenarios where one login can be used across multiple applications, also known as ``single sign-on SSO``

one way of thinking of OIDC is kind of like using an ATM 
The ATM machine is the client, its job is to access data such as your bank balance and perform baking transactions, such as withdraw, deposit, etc..
Bank card is the token that's issued by the bank, it not only gives the atm access to your account the authorization it also has some basic information about who you are, your identity such as your name and authentication information such as when the card expires who issued the card etc..
An ATM cannot work without the unerlying bank infrastructure, similarly ``OIDC`` sits on top of OAuth and cannot work without the underlying OAuth framework 

The difference
in initial request a specific scope of open i is used this lets the auth server know this will be an open id connect exchange the authorization server goes throught all the same steps as before and issues an authorization code back to the client using the resource owners browser  
The key diffrence in OIDC is when the client exchange the authorization code for an access token the client recieves both an access token and ID token as before the access token is ta value the client doesnt understand  
The ID token however is very diffrent the  id token is specificaly formated string of characters known as a JSON web token or JWT
The client can extract information embedded in the JWT such as id name when you logged in, the id tokens expiration 

The data insde the ID Token are called ``claims`` with OIDC there is also a standard way the client can request additional identity information from the authorization server such as your email address using the access token 


## SAML


A Developer's Guide to SAML
https://www.youtube.com/watch?v=l-6QSEqDJPo

security assertion markup language

Standard commonly used for Single Sign-On (SS0)

Standardized way of using xml to facilitate Single Sign-O

If you are developer, this analogy is very helpful:
> SAML is to OIDC as SOAP is to REST. - Joel Franusic

**We may use OpenID connect instead of SAML - its going to be more popular and more modern solution  for new projects.** https://youtu.be/l-6QSEqDJPo

### SAML Terms

Identity Provider (IDP)
The centralized point of authentication that source of truth that identity store.

Service Provider (SP)
The application that the user is trying to sign into.

SAML Request
When the Service Provider sends a communication to the identity provider, this i called a SAML request

SAML Response
When the identity provider responds back or sends a communication to the service provider this is called a saml response 

Assertion
Within the saml response there is going to be multiple statements about the user, these statements that are asserted are called assertions.

XML signatures (DSig)
These assertions are all signed using the XML signatures also known as DSig and they are sent the SAML response is sent to be processed at the service provider to a specific endpoint called an assertion consumer service 

Assertion Consumer Service
Responsible for receiving the SAML response from the identity provider, checking the assertions signatures and validating the entire document.
It's the most important part when implementing SAML in the service provider perspective 

Attributes
Within the SAML response there is going to be other pieces of information about the user, such as first, last name whatever profile information that we might want send along about the user identity, These identity pieces of information are called attributes.

Relay State
A way for identity provider to remember where a user was before authentication, so if the user is browsing anonymously through the service provider and they decide to trigger something that requires authentication they will be redirected to the identity provider.
At that point the ``IDP`` is going to validate the user's identity and redirect them back to the service provider's assertion consumer service

SAML trust
The configuration between the identity provider and the service provider, there are certain pieces of information that are shared, such as the signing certificate as well as an ``entity id`` also known as an ``issuer``

Metadata
Convenience feature that allows self configuration between the ``identity provider`` and the ``service provider`` that means of instead of having to manually grab a certificate, different endpoint URLs, issuer information, etc.. from ``identity provider`` to plug into the ``service provider`` manually and vice versa, the metadata allows you to just share either a XML configuration file or share the URLS to these XML configurations and then the ``service provider`` and ``identity provider`` can self-configure themselves based on information within these configuration files.


WIP image how it works

IDP init
in IDP init is when you have a central portal for all the services, then no SAML request

SP Init
if access the ``SP`` directly SP will make ``SAML Request``
then ``SAML Response`` triggered from IDP


The IDP should know how to recieve a SAML request and how to produce the SAML response
The service provider or the assertion consumer service at the service provider needs to understand how to recieve that SAML response and validate it but then also potentioaly how to generate a saml request if service provider initiated wants 

not all service providers support IDP init and some does not support SP init, this is entiary up to the product and configuration

may support both SP init and IDP init


SAML request sample
TODO XML sample:
- ID in the saml request is generated by the service provider
- IssueInstant - timestamp for the request (point of verification for the identity provider), for example they could only accept request within a specific time frame
- Destination - destination is pointing to the identity provider and is another point of verification. Identity provider can check the destination to ensure that it is the intended recipient of the SAML request
- AssertionConsumerServiceURL - where the response needs to go after the user authenticated, this is again a point of verification, IDP can check if is valid to send the user back there, based on SAML trust we have configured
- Issuer - predefined string thats set up within the SAML trust, the important is that they match that the IDP expect

this XML is stringified encoded and passed in the query string to the identity provider when redirects the user and then thats where the IDP authenticates the user prepares the SAML response

This response is being sent to our services providers assertion consumer service by our identity provider after the user has authenticated

### Provisioning

Keeps identities in sync

IDP should and must be Source of truth

real time provisioning - WIP diagram (IDP hold the responsibilities for keeping user profile within the service provider updated in real time, done with integration for both systems, event base - when IDP profile change trigger an event and update SP user profile)

just in time (JIT) provisioning - WIP diagram (when acc does nto exist in SP to be created or updated)

### Best practices

#### Most common week points:

Flawed assertion validation
if incorrectly implemented at the service provider within the assertion consumer service
essentially if the assertion consumer service isnt validating every single point of validation within the saml response there are exploits that could potentially take place

XML parsers
A lot of times XML parsers contain more features that you actually need and if thouse features if left open or enabled provide a point of exploit for bad actor

Insecure libraries

#### Best practices

- Limit the XML parser
    - Disable document type definition (DTD) fetching
      This is going to protect against XML external entity attacks where the SAML response could be intercepted by a bad actor and then modified to instruct your parser to load external files or resources  
    - Defends agains XML external entities (XXE) attacks
      This could for example be used to load extremely large files which would then allow someone to replay this modifed response and DDOS your assertion  consumer service forcing it to download large files over and over again. It also could be utilized to execute a remote code which be a could be a vig risk to your server 
- Use canonicalized XML - WIP check https://youtu.be/l-6QSEqDJPo?t=1273
    - Normalize XML via specified method / algorithm
    - Protect against Inner comment node manipulation
- Validate the schema
  - Defends against XML signature wrapping (XSW) attacks
  - Adhere to a specific schema outside of the signature
  - use explicit XPath expressions
- Validate every signature
  - Every single assertion should be signed
  - Every signature should be validated
  - Reject partially signed responses
- Limit accepted algorithms
  - Hardcode accepted encryption algorithms
- Use HTTPS
  - Limits exploits that rely on capturing the response
- Validate practices
  - Verify the destination, audience, recipient and issuer match
  - Protects against IDP impersonation
  - Protects against unauthorized lateral movement
- Enforce Validation Window
  - NotBefore and NotOnOrAfter timestamps, should not accept any SAML response that are outside of this window
- Historical Cache
  - Cache equal to double the valid window
  - Record the ID of all responses
  - Reject responses with existing ID'same
  - Limits Replay
- Limit Buffer Standardized
  - Keep buffer size as small as realistically possible
  - Protects against DDOS (so no oversized response or xml to our assertion consumer service with a goal of shutting it down)

### SSO
 
## Duende

Machine to Machine communication
https://docs.duendesoftware.com/identityserver/v5/tokens/requesting/
> In protocol terms, this scenario is called Client Credentials Flow and you can learn more about it in the issuing tokens section as well as in our Quickstart


API auth with tokens

https://docs.duendesoftware.com/identityserver/v5/overview/big_picture/

https://stackoverflow.com/questions/22778315/can-we-use-asp-net-identity-in-domain-driven-design


https://www.youtube.com/watch?v=fhM0V2N1GpY

TO read

IdentityServer4 Setup and Configure Secure Token Service | Tutorial 3
https://medium.com/scrum-and-coke/devkit-webapi-security-tutorial-3-set-up-and-configure-secure-token-service-sts-in-10-minutes-1f7daa44a0e6


client to client identity server

ivaylokenov/Identity-Server-Demystified
https://github.com/ivaylokenov/Identity-Server-Demystified


IMPLEMENTING A MULTI-TENANT OIDC AZURE AD EXTERNAL LOGIN FOR IDENTITYSERVER4
https://damienbod.com/2018/08/15/implementing-a-multi-tenant-oidc-azure-ad-external-login-for-identityserver4/

Using Identity Server for Multi-Tenant Web Applications
https://blog.bitsrc.io/using-identity-server-for-multi-tenant-web-applications-c511ffa3e428

Using Machine to Machine (M2M) Authorization
https://auth0.com/blog/using-m2m-authorization/

Protecting an API using Client Credentials
https://docs.identityserver.io/en/latest/quickstarts/1_client_credentials.html

Clean Architecture - JWT Token Authentication in REST API Using ASP.NET Core Identity
https://medium.com/geekculture/clean-architecture-jwt-token-authentication-in-rest-api-using-asp-net-core-identity-639e4a8f3900

Creating your First IdentityServer4 Solution
https://www.youtube.com/watch?v=HJQ2-sJURvA

IdentityServer
https://www.youtube.com/channel/UCCr3f5a3NBbci6PxljT9VbQ/videos

Using Duende IdentityServer with Entity Framework and ASP.Net Identity
https://www.youtube.com/watch?v=eLRGlnGGUQs

Get a SSO POC running in under 6 minutes with Duende IdentityServer and AdminUI
https://www.youtube.com/watch?v=bflMEJDrmFw&list=PLz9t0GSOz9eCDgLnh7Q3rhA29F3tSekPM

ASP.NET 6 REST API Following CLEAN ARCHITECTURE & DDD Tutorial | Part 1 - Project Setup
https://www.youtube.com/watch?v=fhM0V2N1GpY

Play by Play - Creating APIs for Developers with Identity Server 4
https://www.pluralsight.com/courses/play-by-play-creating-apis-developers-identity-server-four

Securing ASP.NET Core with OAuth2 and OpenID Connect
https://www.pluralsight.com/courses/asp-dotnet-core-oauth2-openid-connect-securing

Getting Started with .NET Core Identity Server 4
https://www.udemy.com/course/getting-started-dot-net-core-identity-server-4/

IdentityServer4 in ASP.NET Core – Ultimate Beginner’s Guide
https://codewithmukesh.com/blog/identityserver4-in-aspnet-core/

IdentityServer4, OAuth, OpenID Connect Series
https://code-maze.com/identityserver-4-series/


