Books::Application.routes.draw do
  get "books/index" => "books#index", :as => :index
  match  "books/add" => "books#add", :via => :post
  match  "books/search" => "books#search", :via => :post
end
