# Example of server-side pagination

!> Work in process!

controller:

```
        [HttpPost]
        [Route("search")]
        [Authorize]
        [SwaggerResponse(HttpStatusCode.OK, "Success.", typeof(PaginationResponseModel<DetailsBuildingResponseModel>))]
        [SwaggerResponse(HttpStatusCode.BadRequest, "Invalid request model.")]
        public IHttpActionResult Search(BuildingsSearchParams model)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            model.Top = model.Top <= 0 ? AppConstants.DefaultItemsPerPage : model.Top;

            var result = this.buildings.Search(model.Name, model.Top, model.Skip);

            var response = new PaginationResponseModel<DetailsBuildingResponseModel>()
            {
                Collection = result.Item1?.AsQueryable().To<DetailsBuildingResponseModel>()?.ToList(),
                Count = result.Item2
            };

            return Ok(response);
        }
```

## Request models:


```
namespace DataTransferModels.SearchParams
{
    public class BuildingsSearchParams
    {
        public string Name { get; set; }
        public int Skip { get; set; }
        public int Top { get; set; }
    }
}
```

## DB query

```
        public (IEnumerable<Building>, int) Search(string name, int top, int skip)
        {
            using (var db = new ApplicationDbContext())
            {
                Expression<Func<Building, bool>> predicate = x => !x.IsDeleted
                                                               && (name == null || x.Name.Contains(name));

                var buildings = db.Buildings.Where(predicate).ToList().Skip(skip).Take(top);
                var count = db.Buildings.Where(predicate).Count();
                return (buildings, count);
            }
        }
```