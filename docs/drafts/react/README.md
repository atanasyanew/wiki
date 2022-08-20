# React 101

```js
npx create-react-app react-tutorial

cd react-tutorial && npm start
```

Project structure:

- ``/public``
- ``/src`` - directory will contain all our React code.


## JSX, JavaScript XML.

JavaScript + XML

> With JSX, we can write what looks like HTML, and also we can create and use our own XML-like tags. Here's what JSX looks like assigned to a variable.

JSX

```jsx
const heading = <h1 className="site-heading">Hello, React</h1>
```

No JSX
```js
const heading = React.createElement('h1', {className: 'site-heading'}, 'Hello, React!')
```

## Components

Almost everything in React consists of components, which can be class components or simple components.

## Simple Components

Simple Component
```jsx
const SimpleComponent = () => {
  return <div>Example</div>
}
```

Class Component
```jsx
class ClassComponent extends Component {
  render() {
    return <div>Example</div>
  }
}
```

Note that if the ``return`` is contained to one line, it does not need parentheses.



## Notes

The ``component`` has their own state
``simple component`` does not have state

ready to use components
https://react-bootstrap.netlify.app/
https://react-bootstrap.github.io/

react bootstrap themes
https://bootswatch.com/


propTypes
https://reactjs.org/docs/typechecking-with-proptypes.html

[Domain-Driven Design With React](https://css-tricks.com/domain-driven-design-with-react/)

[CRACO](https://github.com/gsoft-inc/craco/blob/master/packages/craco/README.md#configuration-file)


SPA routers
https://reactrouter.com/web/example/route-config


Formik - forms utils
https://formik.org/


