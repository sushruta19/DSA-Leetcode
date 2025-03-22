import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    result = views.loc[(views['author_id'] == views['viewer_id']), ['author_id']]
    result = result.rename(columns={'author_id': 'id'}).sort_values(by='id').drop_duplicates()
    return result