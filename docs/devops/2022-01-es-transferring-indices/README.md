# ElasticSearch transferring indices data

*Modified 2022-01-27*

- [ElasticSearch transferring indices data](#elasticsearch-transferring-indices-data)
  - [Motivation](#motivation)
  - [Prerequisites](#prerequisites)
  - [Transferring indices](#transferring-indices)

## Motivation

Most of the times, enterprise applications has serval environments, such as ``DEV``, ``QA/Staging``, ``PRE PROD``, ``PROD``, etc.. you name it.<br>
Those applications are often complex with a lot of business logic, with a grow of complexity the appearance of bugs is also growing.<br>
It's important to note that bugs related with data or its unexpected behavior may exist/reproduce only for some of the environments.<br>
А good practice is to periodically create backups and restores from the main driven environment, in order to have the most relevant data on testing environments.

!> Assumptions:<br>- The source data is not sensitive and its GDPR compliance<br>- The source data is anonymize
  
## Prerequisites

The tool we are going to use is called ``elasticdump``, you may check their repository for more information - [elasticsearch-dump/elasticsearch-dump](https://github.com/elasticsearch-dump/elasticsearch-dump).

Install using ``npm``

```bash
npm install elasticdump -g
elasticdump --help
```

?> Verified with ``elasticdump@6.56.0`` and ``ElasticSearch 6.8.0``

## Transferring indices

Lets assume we have the following index ``app.db.prod.myIndexName``. (A good practice is to use prefix for index names)<br>
In order to avoid confusion, let's assume that ``destination`` is called ``QA`` environment and ``source`` is ``PROD`` environment.<br>
Its important to mention that the destination index must not exist, since we cannot override it.<br>
The idea here it to copy the source index to the destination, using a different name and then adding it to the alias.<br>

1. Find the source index (optional), the following request done via Kibana's dev page.
   ```curl
   GET _cat/indices
   or
   GET _cat/indices/*.db*myIndexName?pretty&v&s=index
   ```
2. Copy the index from source to the destination.<br>
   ```bash
   elasticdump --input=http://sourceIP:9200/app.db.prod.myIndexName --output=http://destinationIP:9200/app.db.qa.202201.myIndexName --type=analyzer
   elasticdump --input=http://sourceIP:9200/app.db.prod.myIndexName --output=http://destinationIP:9200/app.db.qa.202201.myIndexName --type=mapping
   elasticdump --input=http://sourceIP:9200/app.db.prod.myIndexName --output=http://destinationIP:9200/app.db.qa.202201.myIndexName --type=data
   ```
3. Creating an alias for the destination index, using Kibana dev page
   ```curl
   GET _alias
   GET _alias/app.db.prod.myIndexName
   ```
   ```curl
   POST /_aliases?pretty
   {
     "actions": [
       {
         "add": {
           "index": "index_1",
           "alias": "alias_1"
         }
       }
     ]
   }
   ```
4. Delete old indices from the destination environment (if applicable)
