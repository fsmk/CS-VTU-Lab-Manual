class BooksController < ApplicationController
  def index
  end
  def add
	Book.create(:access_no=> params[:b_access_no],:title=> params[:b_title],:author=> params[:b_author],:edition=> params[:b_edition],:publisher=> params[:b_publisher])
	redirect_to :action => 'index'
  end
  def search
  end
end
