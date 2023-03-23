# File-Search
Development of a local
file search engine
# Files specification
config.json:<br>
File where specified name and version of application.
Here you can also change the maximal quantity of relevant pages that will be put into answers.json (max_respones).
Example of the config.json file description:<br>
```json
{
    "requests":
    [
        "some words",
        "some words",
        "some words"
    ]
}
```
answers.json<br>
File where search result will be written in JSON format.<br>
Example content:<br>
```json
{"answers":
{"request0":
{"relevance":
[
  {
    "doc":1,
    "rank":1.0
  },
  {
    "doc":0,
    "rank":0.69000
  }
],
  "result":true
},
  "request1":
  {
    "relevance":
    [
      {
        "doc":0,
        "rank":1.0
      },
      {"doc":1,
        "rank":1.0
      }
    ],
    "result":true
  },
  "request2": {"doc":1,"rank":1.0,"result":true}}
}
```
doc- identification of a relevant<br>
rank - relative index
